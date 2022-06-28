class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int curr_color = image[sr][sc];
    if(curr_color==newColor) return image;
    dfs(image,sr,sc,newColor,curr_color);
    return image; 
  }
  void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,int curr_color)
  {
    if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=curr_color) return;
    image[sr][sc] = newColor;
    dfs(image,sr+1,sc,newColor,curr_color);
    dfs(image,sr-1,sc,newColor,curr_color);
    dfs(image,sr,sc+1,newColor,curr_color);
    dfs(image,sr,sc-1,newColor,curr_color);
  }
  
};
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
        {
            dfs(image,sr,sc,newColor,image[sr][sc]);
        }
        return image;
        
        
    }
    void dfs(vector<vector<int>>& image,int i,int j,int newColor,int oldColor)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=oldColor)
            return;
        image[i][j] = newColor;
        dfs(image,i+1,j,newColor,oldColor);
        dfs(image,i,j+1,newColor,oldColor);
        dfs(image,i-1,j,newColor,oldColor);
        dfs(image,i,j-1,newColor,oldColor);
    }
    
};
*/