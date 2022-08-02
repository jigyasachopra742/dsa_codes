//puri linked lists MapNode type ki hai
//ek bucket aaray bana rahe hai
//usmai different indexes pe key store kar rahe hai
//ek hashing function lete hai which consists of hashcode and compression function which compresses the large index acc to the bucket array size
//supposr string hashing se jaake hashcode generate kar dia 10593 , then we will compress it to fit in bucket array
//hashcode = hashcode % bucketarray size
//voh us index ko us range mai le aayega
#include <iostream>
using namespace std;

template <typename V> //ismei hamne V variable mana hai jismei ham isko koi bhi data type de sakte
class MapNode 
{
    public:
        string key;
        V value; //koi bhi type ham V ko denge , value bhi vahi datatype lelega
        MapNode* next; //next ka address aayega mapNode* type ka

    MapNode(string key, V value) //constructor
    {
        this->key = key; //jis bhi node(MapNode)ke liye constructor bulaya us valo exact node ki key and value jo bhi paas karaya voh lag jayega
        this->value = value;
        next = NULL; //last node
    }

    ~MapNode()  //destructor
    {
        delete next;
    }
};

template <typename V> //int V
class ourmap 
{
    MapNode<V>* bucket; // sari ki linked lists ki nodes ka head    //MapNode<V> is the head of a linkedlist node & MapNode<V>** is the array of those heads.
    int count; //
    int numBuckets; //bucket array ka size hai

    public:
    ourmap() 
    {
        count = 0;
        numBuckets = 5;
        bucket = new MapNode<V>* [numBuckets]; //dynamicaaly creating array
        for (int i = 0; i < numBuckets; i++) 
        {
            bucket[i] = NULL;   //to remove garbage addresses
        }
    }
    //jab dynamically create karte tou delete karna padega
    ~ourmap()  //destroyed
    {
        for(int i = 0; i < numBuckets; i++) 
        {
            delete bucket[i]; //heads ko udhayada
        }
        delete []bucket; //fir pura array udhaya
    }

    int size() 
    { //jase kjase insert hoga vaise count++ hoga
        return count; //hashmap mai kitne elements hai
    }

    //remove karte waqt count-- while destroying ourmap() 

    V getValue(string key)  //SEARCHING FUNCTION
    {
        int bucketIndex = getBucketIndex(key); //hash code is stored
        MapNode<V>* head = bucket[bucketIndex]; //address is stored
        while (head) 
        {
            if (head->key == key) 
            {
                return head->value;
            }

            head = head->next;
        }

        return 0; //agar nahi milta tou 
    }

    double getLoadFactor() 
    {
        return (1.0*count) // numBuckets; //to avoid concentration of elements
    }

    private:
    int getBucketIndex(string key)  //hashing function
    {
        int hashCode = 0;
        int currentCoeff = 1;
        
        for (int i = key.length() - 1; i >= 0; i--)  //string = "abc"
        {
            hashCode += key[i] * currentCoeff;
            hashCode %= numBuckets; //to prevent it from going out of range, we keep % it by numBuckets at every step
            currentCoeff *= 37; //take any prime no. as base coz prime nos. are proven to give better spread out results.
            currentCoeff %= numBuckets; //coz (n1*n2*n3)%r = ((n1%r)(n2%r)(n3%r))%r
        }

        return hashCode % numBuckets; //yeh hashcode ko particualr range mai laane ke liye kara hai , optimization like binary search ,  equal parts mai divide kar dia
    }

    void rehash() 
    {
        MapNode<V>** temp = bucket; //purane pe point kar raha hai
        bucket = new MapNode<V>* [2 * numBuckets];
        for (int i = 0; i < 2*numBuckets; i++) 
        {
            bucket[i] = NULL;
        }

        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        //now it has become a completely new empty map.
        for (int i = 0; i < oldBucketCount; i++) 
        {
            MapNode<V>* head = temp[i];
            while (head) 
            {
                string key = head->key;
                V value = head->value;
                insert(key, value); //will insert in bucket array.
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++) 
        {
            MapNode<V>* head = temp[i];
            delete head;
        }
            delete []temp;
    }

    public:
    void insert(string key, V value)  //INSERT
    {
        int bucketIndex = getBucketIndex(key); //hashcode
        MapNode<V>* head = bucket[bucketIndex]; //address
        while (head != NULL) //already exists
        {
            if (head->key == key) 
            {
                head->value = value;
                return;
            }

            head = head->next;
        }
        
        //does not exist
        head = bucket[bucketIndex]; //if control has come to this point without returning from while loop means key does not exist.
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head; //insert new node at the beginning of this linked list
        bucket[bucketIndex] = node;
        count++;

        //optimizing time complexity with rehashing
        double loadFactor = (1.0 * count) / numBuckets;   //1.0 done coz int/int will not give decimal results
        if (loadFactor > 0.7) 
        {
            rehash(); //agar 0.7 se badha ho gaya
        }
    }

    V remove(string key)  //REMOVE
    {
        int bucketIndex = getBucketIndex(key); //hashcode is stored
        MapNode<V>* head = bucket[bucketIndex]; //address is stored
        MapNode<V>* prev = NULL; //previous pointer banaya taaki remove karte waqt jo prev ka next hai usse next pe point kara denge
        while (head != NULL)  
        {
            if (head->key == key) 
            {
                if (prev == NULL)  //phele node pe mil gyaa
                { //if the key is found at the first node itself, bucket address needs to be replaced with the next node's address
                    bucket[bucketIndex] = head->next; //1st node ka head uske next pe store kara liya aur 1st ko delete kar diya
                }
                else 
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;  //without this if we call delete, it will delete all nodes after it as well coz this destructor is written recursively.
                delete head; //yeh return karne ke liye jo remove ho raha hai
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }
        return 0;   //nahi mila tou returnn 0 . if V would be ptr, 0 wud be NULL, for int also no problem, hence 0.
    }
};

int main() 
{
    ourmap<int> map; //ourmap ke liye int v ho gaya ho gaya
    for (int i = 0; i < 10; i++) 
    {
        char c = '0' + i;   //converting i to char
        string key = "abc" + c;
        int value = 1 + i;
        map.insert(key, value);
        cout<<map.getLoadFactor()<<endl;    //to see if rehashing is working
    }

    // for (int i = 0; i < 3; i++) {
    //     char c = '0' + i;   //converting i to char
    //     string key = "abc" + c;
    //     int value = 1 + i;
    //     map.insert(key, value);
    //     cout<<map.getLoadFactor()<<endl;    //to see if rehashing is working
    // }

    cout<<map.size()<<endl;
    cout<<map.remove("abc2")<<endl;
    cout<<map.remove("abc7")<<endl;
    cout<<map.size()<<endl;

    for (int i = 0; i < 10; i++) 
    {
        char c = '0' + i;
        string key = "abc" + c;
        cout<<key<<": "<<map.getValue(key)<<endl;
    }

    return 0;
}