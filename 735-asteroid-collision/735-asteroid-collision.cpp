class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int> res;
      res.push_back(asteroids[0]);
      int i= 1;
      int n = asteroids.size();
      while(i<n)
      {
        if(res.size()==0) res.push_back(asteroids[i]),i++;
        else if(asteroids[i]>0 && res.back()<0) res.push_back(asteroids[i]),i++;
        else if((asteroids[i]>0 && res.back()>0) || (asteroids[i]<0 && res.back()<0))
        {
          res.push_back(asteroids[i]);
          i++;
        }
        else
        {
          if(abs(asteroids[i])==abs(res.back()))
            res.pop_back(),i++;
          else if(abs(asteroids[i])>abs(res.back()))
            res.pop_back();
          else
            i++;
             
        }
           
      }
      return res;
        
    }
};