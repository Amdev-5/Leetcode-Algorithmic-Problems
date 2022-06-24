class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
      if(points.size()==1) return 0;
      int res = 0;
      for(int i =1;i<points.size();i++)
      {
        res+= max(abs(points[i-1][0]-points[i][0]),abs(points[i-1][1]-points[i][1]));  
      }
      return res;        
    }
};
/*
4/4 = 1
3/2
if(y1-y2==0 || x1-x2==0 || y1-y2==x1-x2) return(distance euclid)
else
m = 1.5
1,1   - 3,3|| 4,4

*/