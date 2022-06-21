class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
      if(turnedOn>8) return res;
      //10 bits
      //if set bit==turnedOn and time lies in range then puch back also 
      //while pushing make sure Hr is having no leading 0
      // minute is having leading 0 if it is 1-9
      //hr is in range 0-11 and minute is in range 0-59
      for(int i=0;i<(1<<4);i++)
      {
        if(i>11) break;
        for(int j=0;j<(1<<6);j++)
        {
          if((count(i)+count(j))!=turnedOn) continue;
          string s="";
          if(j>59)
            break;
          if(i<10)
          {
            //s+='0';
            s+=to_string(i);
            s+=':';
          }
          else
          {
            s+=to_string(i);
            s+=':';
          }
          if(j<10)
          {
            s+='0';
          }
          s+=to_string(j);
          res.push_back(s);
        }
        
        
      }
      return res;
      
    }
  int count(int n)
  {
    int res = 0;
    while(n>0)
    {
      n = (n)&(n-1);
      res++;
    }
    return res;
    
  }
  
};