class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n);
      vector<pair<int,int>> v(n);
      for(int i = 0;i<n;i++)
      {
        v[i] = {nums[i],i};
      }
      merge(v.begin(),v.end(),res);
      return res;
      
    }
  void merge(vector<pair<int,int>>::iterator begin,vector<pair<int,int>>::iterator end,vector<int> & res)
  {
    if(end-begin<=1) return;
    auto mid = begin + (end-begin)/2;
    merge(begin,mid,res);
    merge(mid,end,res);
    for(auto i = begin,j = mid;i!=mid;i++)
    {
      while(j!=end && i->first > j->first) ++j;
      res[i->second]+=j-mid;
    }
    inplace_merge(begin,mid,end);
  }
};
/*

5 2 6 1
2  1  1 0
*/
