class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
      vector<int> result;
      //'int n = nums[0].size();
      for(auto x: queries)
      {
        priority_queue<pair<string,int>> pq;
        for(int i = 0;i<nums.size();i++)
        {
          int t = nums[i].length()-x[1];
          string p = nums[i].substr(t,x[1]);
          if(pq.size()<x[0])
          {
            pq.push({p,i});
          }
          else
          {
            if(pq.top().first>p)
            {
              pq.pop();
              pq.push({p,i});
            }
          }
        }
        result.push_back(pq.top().second);
      }
      return result;
        
    }
};
/*
1 2 3 4 5 
2rd smallest
n-2+1
1 2 3
*/
