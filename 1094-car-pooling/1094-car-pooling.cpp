class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      /*sort(trips.begin(),trips.end(),[](const vector<int> & a,const vector<int> & b )
           {
             return a[1]<b[1] || (a[1]==b[1] && a[2]<b[2]);
           });
           */
      vector<int> people(10001,0);
      for(int i = 0;i<trips.size();i++)
      {
        for(int j = trips[i][1];j<trips[i][2];j++)
        {
          people[j]+=trips[i][0];
        }
      }
      for(int i = 0;i<=1000;i++)
      {
        //cout<<people[i]<<" ";
        if(people[i]>capacity) return false;
      }
      return true;
      
        
    }
};