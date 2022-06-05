class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      int idx = 0,count=1;
      for(int i=1;i<nums.size();i++)
      {
        if(nums[i]-nums[idx]>k)
        {
          count++;
          idx=i;
        }
      }
      return count;
      /*
      vector<vector<int>> v;
      vector<vector<int>> m;
      v.push_back({nums[0]});
      m.push_back({nums[0],nums[0]});
      for(int i = 1;i<nums.size();i++)
      {
        bool flag = false;
        for(int j = 0;j<v.size();j++)
        {
          if(nums[i]<m[j][1] && m[j][1]-nums[i]<=k)
          {
            m[j][0] = nums[i];
            v[j].push_back(nums[i]);
            flag = true;
            break;
          }
          if(nums[i]>m[j][0] && nums[i]-m[j][0]<=k)
          {
            m[j][1] = nums[i];
            v[j].push_back(nums[i]);
            flag = true;
            break;
          }
          if(nums[i]<=m[j][1] && nums[i]>=m[j][0])
          {
            v[j].push_back(nums[i]);
            flag = true;
            break;
          }
        }
        if(flag==false)
        {
          v.push_back({nums[i]});
          m.push_back({nums[i],nums[i]});
          flag = true;
        }
      }
      return v.size();
      */
        
    }
};