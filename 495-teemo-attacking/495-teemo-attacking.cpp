class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
      vector<vector<int>> temp;
      for(int i = 0;i<t.size();i++)
      {
        temp.push_back({t[i],t[i]+d-1});
      }
      sort(temp.begin(),temp.end());
      int res = 0;
      int mini = temp[0][0];
      int maxi = temp[0][1];
      for(int i = 1;i<temp.size();i++)
      {
        if(temp[i][0]<=maxi)
        {
          maxi = max(maxi,temp[i][1]);
        }
        else
        {
          res+=(maxi-mini+1);
          mini = temp[i][0];
          maxi = temp[i][1];
        }
      }
      res+=(maxi-mini+1);
      return res;
      
        
    }
};