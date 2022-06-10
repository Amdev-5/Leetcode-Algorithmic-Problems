class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
      unordered_map<char,int> m;
      int count = 0;
      for(int i = 0;i<tasks.size();i++)
      {
        m[tasks[i]]++;
        count = max(count,m[tasks[i]]);
      }
      int ans = (count-1)*(n+1);
      for(auto t: m)
      {
        if(t.second==count) ans++;
      }
      return max((int)tasks.size(),ans);
    }
};