class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      sort(tokens.begin(),tokens.end());
      int i = 0;
      int j = tokens.size()-1;
      int curr_power = power;
      int score = 0;
      while(i<j)
      {
        if(curr_power>=tokens[i])
        {
          score++;
          curr_power-=tokens[i];
          i++;
        }
        else
        {
          if(score==0) return score;
          curr_power+=tokens[j];
          j--;
          score--;
        }
      }
      cout<<i<<" "<<j<<" "<<curr_power<<" ";
      //i++;
      if(i<tokens.size() && curr_power>=tokens[i])
        score++;
      return score;
      
        
    }
};