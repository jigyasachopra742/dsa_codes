//parent pointers
//distance: upwards downwards
class Solution {
public:
    
    void markParents(TreeNode* root, TreeNode* target, unordered_map<TreeNode* , TreeNode*> &p_map)
    {
        //WE HAVE MADE THE PARENT MAP SO THAT THE TARGET CAN MOVE TO IT'S PARENT NODES AS WELL
        //SO THAT NODES CAN MOVE UPWARDS
        //map is for storing parents
        if(root == NULL)return;
        
        queue<TreeNode*> p_queue; 
        p_queue.push(root); //push 3
        
        while(p_queue.size() != 0)
        {
            TreeNode* curr = p_queue.front(); //3 
            p_queue.pop();
            
            if(curr->left != NULL) //3 ka left 5
            {
                //mark left ka parent node itself
                p_map[curr->left] = curr; //MARKING THE PARENT NODES
                p_queue.push(curr->left); //IF THERE LEFT CHILDREN EXISTS PUSH THEM IN PARENT QUEUE //5 is pushed in queue and parent is 3
            }
            //store the parent of 5 and 1 in map 
            if(curr->right != NULL)
            {
                p_map[curr->right] = curr; //MARKING THE PARENT NODES
                p_queue.push(curr->right); //IF THERE are RIGHT CHILDREN EXISTS PUSH THEM IN PARENT QUEUE
                //1 is pushed in queue and parent is 3
            }
            
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode* , TreeNode*> p_map; //parent map
        //NODES AT A DISTANCE K
        markParents(root, target, p_map); //for marking parents
        
        unordered_map<TreeNode* , bool> visited; //2nd bfs for distance
        
        queue<TreeNode* > c_queue;
        c_queue.push(target); //pushing the target
        visited[target] = true; //that target 5 is already marked ab uske aas paas dekhenge distance ko
        int level = 0;
        
        while(c_queue.size() != 0)
        {
            int curr_size = c_queue.size();
            if(level == k)
            {
                break;
            }
            
            for(int idx = 0; idx < curr_size; idx++)
            {
               TreeNode* curr = c_queue.front();
               c_queue.pop();
                
               if(curr->left && !visited[curr->left]) //left node
               {//if left node exists and it is not marked in visited map
                   c_queue.push(curr->left);
                   visited[curr->left] = true; //mark 6 as true
               }
                
               if(curr->right && !visited[curr->right]) //right node
               {//if right node exists and it is not marked in visited map
                   c_queue.push(curr->right);
                   visited[curr->right] = true; //mark 2 as true
               }
                
               if(p_map[curr] && !visited[p_map[curr]]) //parent node in map p_map
               { //if parent node exists in map and it is not marked in visited map
                   c_queue.push(p_map[curr]);
                   visited[p_map[curr]] = true; //mark 3 as true
               }
                //ALL 2, 3, 6 ARE AT A DISTANCE K
                //THEN PUSH THERE LEFT AND RIGHT IF THEY ARE NOT MARKED IN MAP
                //THEN INCREASE THE DISTANCE
            }
            
            level++;
            
        }
        
        vector<int> result;
        
        while(c_queue.size() != 0)
        {
            TreeNode* curr = c_queue.front();
            c_queue.pop();
            
            result.push_back(curr->val);
        }
        
        return result;
        
    }
};