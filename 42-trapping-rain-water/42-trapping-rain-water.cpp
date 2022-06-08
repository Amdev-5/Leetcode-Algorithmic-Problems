class Solution {
public:
    int trap(vector<int>& height) {
      //sum(min(max(left),max(right))) at each i 
      int n = height.size();
      vector<int> left(n,0);
      vector<int> right(n,0);
      left[0] = height[0];
      right[n-1] = height[n-1];
      for(int i=1;i<n;i++)
      {
        left[i] = max(left[i-1],height[i]);
      }
      for(int i = n-2;i>=0;i--)
      {
        right[i] = max(right[i+1],height[i]);
      }
      int water = 0;
      
      for(int i = 0;i<n;i++)
      {
        water+=(min(left[i],right[i])-height[i]);
      }
      
      return water;
      
      
      
      
      
      
      /*
        int n = height.size();
        vector<int> left[n];
        vector<int> right[n];
        begin(left)=begin(height);
        for(int i=0;i<n;i++)
        {
            left[i] = max(left[i-1],height[i]);

        }
        end(right)= end(height);
        for(int i=n-2;i>0;i--)
        {
            right[i] = max(right[i+1],height[i]);

        }
        int water = 0;
        
        for(int i=0;i<n;i++)
        {
            water = water+(min(left[i],right[i])-height[i]);
            
            
        }
        return water;
        */
        
        
    }
};