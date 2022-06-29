class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      //priority_queue<pair<int,int>> pq;
      unordered_map<int,int> m;
      for(int i = 0;i<nums.size();i++)
      {
        m[nums[i]]++;
      }
      vector<int> res;
      priority_queue<pair<int,int>> pq; //frq,number
      for(auto t:m)
      {
        pq.push({t.second,t.first});
        if(pq.size()>m.size()-k)
        {
          res.push_back(pq.top().second);
          pq.pop();
        }
          //pq.pop();
      }
      return res;
      /*
      vector<pair<int,int>> v;
      for(auto t: m)
      {
        v.push_back({t.first,t.second});
      }
      sort(v.begin(),v.end(),[](const pair<int,int> & a, const pair<int,int> & b)
           {
             return a.second>=b.second;
           });
      vector<int> res;
      for(int i = 0;i<k;i++)
      {
        res.push_back(v[i].first);
      }
      return res;
      */
        
    }
};