class Solution 
{
public:
    
    void fill(vector<vector<int>>& image , int sr ,int sc , int newColor ,int val)
    {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] == newColor||image[sr][sc] != val)
        {
            return;
        }
        
       
        
        image[sr][sc] = newColor;
        
        fill(image , sr - 1  , sc , newColor ,val);
        
        fill(image , sr  , sc - 1 , newColor,val);
        
        fill(image , sr + 1 , sc , newColor,val);
        
        fill(image, sr , sc + 1 , newColor,val);
        
        //image[sr][sc] = temp;   //unmarked
        
        
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
       
        fill(image , sr , sc, newColor ,image[sr][sc]); //image[sr][sc] is the starting pixel , take it as val
        return image;
    }
};