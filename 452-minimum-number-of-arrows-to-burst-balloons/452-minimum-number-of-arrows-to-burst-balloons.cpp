class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
      sort(points.begin(),points.end());
      int maxi=points[0][1];
      int res = 1;
      for(int i = 1;i<points.size();i++)
      {
        if(points[i][0]>maxi)
        {
          res++;
          maxi = points[i][1];
        }
        else
        {
          maxi  = min(maxi,points[i][1]);
        }
      }
      return res;
        
    }
};
/*
[[1,6],[2,8],[7,12],[10,16]]
res = 1; maxi = 6;
i=1; res = 1; maxi = 6;
i = 2; res = 2; maxi  = 12
i = 3 res = 
[[1,10],[3,9],[4,11],[6,7],[6,9],[8,12],[9,12]]
*/