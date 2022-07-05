class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0) return 0;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i = 0;i<nums.size();i++)
    {
      pq.push(nums[i]);
    }
    int res = 1;
    int curr = 1;
    int ele = pq.top();
    pq.pop();
    while(!pq.empty())
    {
      int z = pq.top();
      pq.pop();
      if(z==ele+1)
      {
        curr++;
        ele = z;
      }
      else if(z==ele)
      {
        //curr++;
      }
      else
      {
        res = max(res,curr);
        curr = 1;
        ele = z;
      }
    }
    res = max(curr,res);
    return res;
  }
};
























  /*
    int longestConsecutive(vector<int>& nums) {
      if(nums.size()==0)
        return 0;
      priority_queue <int, vector<int>, greater<int>> p;
      for(int i = 0;i<nums.size();i++)
      {
        p.push(nums[i]);
      }
      int res = 0;
      int curr = 1;
      int curr_ele = p.top();
      p.pop();
      while(!p.empty())
      {
        if(p.top()==curr_ele+1)
        {
          curr++;
          curr_ele = p.top();
          p.pop();
        }
        else if(p.top()==curr_ele)
        {
          p.pop();
        }
        else
        {
          res = max(curr,res);
          curr = 1;
          curr_ele = p.top();
          p.pop();
        }  
      }
      res = max(res,curr);
      return res;
    }
};
*/