class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
      sort(matchsticks.begin(),matchsticks.end(),greater<int>());
      int sum = 0;
      for(int i = 0;i<matchsticks.size();i++)
      {
        sum+=matchsticks[i];
      }
      if(sum%4!=0) return false;
      sum = sum/4;
      int s1 = sum,s2=sum,s3=sum,s4=sum;
      return rec(matchsticks,0,s1,s2,s3,s4);
      //now we have to find 4 exclusie numbers sets giving sum
      
        
    }
  bool rec(vector<int>& m,int ind,int s1, int s2,int s3,int s4)
  {
    if(ind==m.size())
    {
      if(s1==0 && s2==0 && s3==0 && s4==0)
      {
        return true;
      }
      else
        return false;
    }
    bool flag = false;
    if(s1>=m[ind]) flag = flag || rec(m,ind+1,s1-m[ind],s2,s3,s4);
    if(s2>=m[ind]) flag = flag || rec(m,ind+1,s1,s2-m[ind],s3,s4);
    if(s3>=m[ind]) flag = flag || rec(m,ind+1,s1,s2,s3-m[ind],s4);
    if(s4>=m[ind]) flag = flag || rec(m,ind+1,s1,s2,s3,s4-m[ind]);
    return flag;
  }
};