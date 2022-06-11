class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;
    int n = nums.size();
    int pre = nums[0];
    m1[pre] = 1;
    for(int i =1;i<n;i++)
    {
      pre = pre+nums[i];
      m1[pre] = i+1;
    }
    pre = nums[n-1];
    m2[pre] = 1;
    int counter = 1;
    for(int i = n-2;i>=0;i--)
    {
      pre+=nums[i];
      counter++;
      m2[pre] = counter;
    }
    int res = INT_MAX;
    for(auto t: m1)
    {
      int diff=x-t.first;
      if(t.first==x) res = min(res,t.second);
      if(m2.find(diff)!=m2.end() && t.second+m2[diff]<=n)
      {
        res = min(res,t.second+m2[diff]);
      }
    }
    for(auto t: m2)
    {
      int diff = x-t.first;
      if(t.first==x) res = min(res,t.second);
      if(m1.find(diff)!=m1.end() && t.second+m1[diff]<=n)
      {
        res = min(res,t.second+m1[diff]);
      }
    }
    
    if(res==INT_MAX) return -1;
    return res;
  }
};

  /*
  int res = INT_MAX;
    int minOperations(vector<int>& nums, int x) {
      int i= 0;
      int j =nums.size()-1;
      rec(nums,i,j,x,0);
      if(res==INT_MAX) return -1;
      return res;
    }
  void rec(vector<int>& nums,int i,int j,int x,int op)
  {
    if(x<0) return;
    else if(x==0)
    {
      res=min(res,op);
    }
    else if(i>j) return;
    else
    {
      rec(nums,i,j-1,x-nums[j],op+1);
      rec(nums,i+1,j,x-nums[i],op+1);
    }
  }
};
*/
/*
3 5 25 26 27 30
3 4 5 25 27 30

*/