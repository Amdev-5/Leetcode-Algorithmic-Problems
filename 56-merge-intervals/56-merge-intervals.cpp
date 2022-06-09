class Solution {
public:
  //sort, initialize mini maxi with first interval, run a loop compare intervals[i][0] with maxi if it is less than update maxi as max(maxi,intervals[i][1]) else res.push_back({mini,maxi}) and update mini and maxi with the new interval
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(),intervals.end());
    int mini= intervals[0][0];
    int maxi = intervals[0][1];
    for(int i=1;i<intervals.size();i++)
    {
      if(intervals[i][0]<=maxi)
      {
        maxi = max(intervals[i][1],maxi);
      }
      else
      {
        res.push_back({mini,maxi});
        mini = intervals[i][0];
        maxi = intervals[i][1];
      }
    }
    res.push_back({mini,maxi});
    return res;
    
    
  }
};
/*
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]); 
        for(int i = 1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=res.back()[1])
            {
                res.back()[1] = max(intervals[i][1],res.back()[1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
            
        }
        return res;
        
    }
};
*/