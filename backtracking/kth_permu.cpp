class Solution {
public:
    //APPROACH: n=4( matlab ki elements will be 1,2,3,4)(indexing: 0,1,2,3), k = 17 = 16th permuation dekh rahe hai, so which will be the first number in 16th permutation, as we can see it is 3. Every range is containing 6 numbers, so 16/6 = 2 , so we are considering 0-based indexing so the number at 2 index is 3, so permutation starts with number 3. (3 - - - )
    
    //let's start our permuation from 1, we will get 1 + (2,3,4) = 3!=6 = [0-5]
                                                //2 + (1,3,4) = 3!=6=[6-11]
                                                //3+(1,2,4) = 3!=6=[12-17](yaha dekh)
                                                //4 + (1,2,3) = 3!=6[18-23]
    //6 + 6 + 6 + 6 = 24 total unique permutations
    //MARK all the permutations with 0-based indexing that means 0-23 tak
    //1 2 3 4 = {0}
    //4 3 2 1 = {23rd}
    
    //Now we will find the remaining numbers, 16%6 = 4th sequence out of 6. Set of numbers remaining = {1,2,4} , k = 4 , 4th sequence among them. permutation is goin to start with  1 or 2 or 4   //every one is having 2 permutations, k/2 = 4/2 = 2      
                //0. 1 + {2,4} = 2! = 2 = [0-1]
                // 1. 2 + {1,4} = 2! = 2 = [2-3]
                // 2. 4 + {1,2} = 2! = 2 = [4-5] = 6 permutations(yaha dekho 2 index)
 
  
       //so 4 will be the next number //3 4 
    
//NOW we will find the remaining numbers , 4%2 = 0th sequenence out of 4. Set of remaining numbers = [1,2], k =0, 0th permutation among them. Permutation is goin to start with 1 or 2. Everyone is having 1 permutation, total of 2 permutations
    //0. 1 + {2} = 1! = 1 [0-0]
    //1. 2 + {1} = 1! = 1 [1-1]
    //= 2 total permutations
    //k/1 = 0/1 = 0th index pe konsa hai . So 1 block is having permutation , 1 is the 3rd number(3,4,1)
    
    //NOw we will look for remaining characters that is 0%1 = 0th sequuence out of 0. Set of remaining numbers = [2], k = 0, 0th permutation among them. Permutation is goin to start with 2. Having 0 permutations
    //0. 2 + {} = 0! = 1 = Last number in permutation will be 2
    //(3,4,1,2) (FINAL ANSWER) 
    string getPermutation(int n, int k) 
    {
        vector<int> nums; //array nums isiliye bana rahe taaki traverse karke permutations bana sake
        int fact = 1;
        
        for(int idx = 1; idx < n; idx++)
        {
            fact = fact * idx ; //pushing 1,2,3 // calculating factorial = 6
            nums.push_back(idx);
        }
        
        nums.push_back(n); //pushing the last ele that is 4 so array is nums=[1,2,3,4]
        string ans = "";
        k = k - 1; //since indexing is from 0 that is why 0-2 = 3 permutations
        while(true) //ab voh particular index pe ek number daal rahe
        {
            ans = ans + to_string(nums[k/fact]); //pushing 3 
            nums.erase(nums.begin() + k/fact); //erasing 3
            if(nums.size() == 0)
            {
                break;
            }
            
            k = k % fact; //for remaining numbers
            fact = fact/nums.size(); //for factorial example = 4/2 = k = 4 , fact = 2
        }
        
        return ans;
    }
};