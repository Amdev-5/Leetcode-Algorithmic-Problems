class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
      unordered_map<int,int> indi;
      vector<string> res(score.size(),"");
      for(int i =0;i<score.size();i++)
      {
        indi[score[i]] = i;
      }
      sort(score.begin(),score.end());
      for(int i =score.size()-1;i>=0;i--)
      {
        if(i==score.size()-1)
        {
          res[indi[score[i]]] = "Gold Medal";
        }
        else if(i==score.size()-2)
        {
          res[indi[score[i]]] = "Silver Medal";
        }
        else if(i==score.size()-3)
        {
          res[indi[score[i]]] = "Bronze Medal";
        }
        else
        {
          res[indi[score[i]]] = (to_string(score.size()-i));
        }
      }
      return res;
      
      
        
    }
};