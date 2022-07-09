class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      int n = nums.size();
      priority_queue<pair<int,int>> pq; // int , index
      vector<int> dp(n,INT_MIN);
      dp[0] = nums[0];
      pq.push({nums[0],0});
      for(int i = 1;i<n;i++)
      {
        while((i-pq.top().second)>k) pq.pop();
        dp[i] = pq.top().first+nums[i];
        pq.push({dp[i],i});
      }
      /*for(int i = 0;i<n;i++)
      {
        cout<<dp[i]<<" ";
      }*/
      return dp[n-1];
        
    }
};