class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
      priority_queue<pair<long long,long long>,vector<pair<long long , long long >>,greater<pair<long long, long long>>> pq;
      long long sum = 0;
      long long ans = 1e18;
      for(long long i = 0;i<nums.size();i++)
      {
        sum+= (long long)nums[i];
        if(sum>=k)
        {
          ans = min(ans,i+1);
        }
        while(pq.size() && sum-pq.top().first>=k)
        {
          auto &p =  pq.top();
          ans = min(ans,i-p.second);
          pq.pop();
        }
        pq.push({sum,i});
      }
      if(ans==1e18) return -1;
      return ans;
      /*int n = nums.size();
      int i = 0;
      int j = 0;
      int res = INT_MAX;
      int sum = 0;
      for(int j=0;j<n;j++)
      {
        sum+=nums[j];
        if(sum>=k)
        {
          
        }
        int t= i;
        while(t<=j)
        {
          cout<<sum<<" "<<i<<" "<<j;
          res = min(res,j-i+1);
          sum-=nums[i];
          i++;
        }
      }
      if(res==INT_MAX) return -1;
      return res;
      */
      
        
    }
};