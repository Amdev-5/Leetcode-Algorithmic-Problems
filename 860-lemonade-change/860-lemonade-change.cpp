class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      //sort(bills.begin(),bills.end());
      int count_5 = 0;
      int count_10 = 0;
      int i = 0;
      int n = bills.size();
      while(i<n)
      {
        if(bills[i]==5) count_5++,i++;
        else if(bills[i]==10)
        {
          if(count_5<1) return false;
          else count_5--, count_10++,i++;
        }
        else
        {
          if(count_5<1) return false;
          if(count_10>0)
          {
            count_10--;
            count_5--;
            i++;
          }
          else if(count_5>=3)
          {
            count_5 = count_5-3;
            i++;
          }
          else
          {
            return false;
          }
        }
      }
      
      
      return true;
        
    }
};