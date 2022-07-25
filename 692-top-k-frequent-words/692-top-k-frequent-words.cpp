class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string,int> count;
      for(string word: words)
      {
        count[word]++;
      }
      int n = count.size();
      vector<pair<int,string>> v;
      for(auto t: count)
      {
        v.push_back({t.second,t.first});
      }
      /*
      priority_queue<pair<int,string>,vector<pair<int,string>>, greater<pair<int,string>>> pq;
      for(auto t: count)
      {
        pq.push({t.second,t.first});
        if(pq.size()>n-k)
        {
          v.push_back(pq.top());
          pq.pop();
        }
      }
      */
      sort(v.begin(),v.end(),[](const pair<int,string> & a, const pair<int,string> & b)
           {
             return a.first> b.first || (a.first==b.first && a.second<b.second);
           });
           
      vector<string> result;
      for(int i = 0;i<k;i++)
      {
        result.push_back(v[i].second);
      }
      return result;
    }
};