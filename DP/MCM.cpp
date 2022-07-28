class Solution{
public:

    int t[101][101]; //global
    
    int solve(int arr[], int start_idx , int end_idx)
    {
       //arr = [40, 20, 30, 10, 30]
       
       //for(i to k)
       //40*20 20*30 = 40*20*30 => 40*30 = C1
       //for(k+1 to j)
       //30*10 10*30 = 30*10*30 => 30*30 = C2
       //C3 = 40*30 30* 30 => 40*30*30 => arr[i - 1] * arr[k] * arr[j]
       //MIN COST = C1 + C2 + C3
       
        if(start_idx >= end_idx)
        {
            return 0;
        }
        
        if(t[start_idx][end_idx] != -1) //if that value is already presnt in the matrix then we do not
        //have to again do the recursive calls , simply return the value and save time;
        {
            return t[start_idx][end_idx]; //return t[i][j]
        }
        //I > J MEANS SIZE IS  0 (doubt)
        //I == J MEANS SIZE IS 1 , AGAR SIZE 1 HAI TOU PICHLE ELEMENT SE KASE COMPARE KARENGE
        //K IS FOR PARTIONING
        int mn = INT_MAX;
        for(int k = start_idx; k < end_idx; k++)
        {
            int temp_ans = solve(arr, start_idx, k) + solve(arr, k + 1, end_idx) + (arr[start_idx-1]* arr[k] * arr[end_idx]);
            if(temp_ans < mn)
            {
                mn = temp_ans;
            }
        }
        
        return t[start_idx][end_idx] = mn;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
       for(int i =0;i<101;i++){
           for(int j =0;j<101;j++){
               t[i][j] = -1;
           } //PURI MATRIX MAI TRAVERSE KARKE -1 DAALDO
       }
        
        return solve(arr, 1, N-1);
        
        
        
        
    }
};