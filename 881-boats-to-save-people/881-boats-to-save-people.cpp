class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      unordered_map<int,bool> m;
      sort(people.begin(),people.end());
      for(int i =0;i<people.size();i++)
      {
        m[i] = false;
      }
      int i = 0;
      int j = people.size()-1;
      int count = 0;
      while(i<j)
      {
        if(people[i]+people[j]>limit) j--;
        else
        {
          count++;
          m[i] = true;
          m[j]=true;
          i++;
          j--;
        }
        
      }
      for(auto t: m)
      {
        if(t.second==false)
        {
          count++;
        }
      }
      return count;
      
        
    }
};