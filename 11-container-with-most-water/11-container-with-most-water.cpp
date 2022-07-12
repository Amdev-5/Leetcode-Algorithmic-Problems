class Solution {
public:
    int maxArea(vector<int>& height) {
      int i = 0;
      int j = height.size()-1;
      int res = INT_MIN;
      while(i<j)
      {
        if(height[i]<=height[j])
        {
          int water = height[i]*(j-i);
          res = max(res,water);
          i++;
        }
        else
        {
          int water = height[j]*(j-i);
          res = max(res,water);
          j--;
        }
      }
      return res;
    }
};
/*
water = min(height[j],height[i])* (j-i)
1 
1 2 3 4 5 6 7 8
    6 4 15 16 40 18 49
    2 10 
*/