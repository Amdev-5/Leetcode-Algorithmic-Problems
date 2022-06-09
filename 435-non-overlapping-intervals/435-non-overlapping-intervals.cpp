class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int res = 0;
      sort(intervals.begin(),intervals.end());
      int mini = intervals[0][0];
      int maxi = intervals[0][1];
      for(int i= 1;i<intervals.size();i++)
      {
        if(intervals[i][0]<maxi)
        {
          res++;
          cout<<i<<" ";
          if(intervals[i][1]<maxi)
          {
            mini = intervals[i][0];
            maxi = intervals[i][1];
          }
        }
        else
        {
          mini = intervals[i][0];
          maxi = intervals[i][1];
        }
      }
      return res;
        
    }
};
/*
sort
[[1,2],[1,3],[2,3],[3,4]]
if(nums[i][0]<nums[i-1][1])
{
if(nums[i-1][1]>nums[i][1])
{
mini = nums[i][0]
maxi = nums[i][0]
res++;
}
}




*/