class Solution {
public:
    int myAtoi(string s) {
      int sign = 1;
      int i = 0;
      int res = 0;
      while(s[i]==' ') i++;
      if(s[i]=='-' || s[i]=='+')
      {
        if(s[i]=='-') sign = -1;
        i++;
      }
      for(;i<s.length() && s[i]>='0' && s[i]<='9';)
      {
        int no = s[i]-'0';
        if(((res)>(INT_MAX/10)) || (res*10 > INT_MAX-no)){
          if(sign==1)
          {
            return INT_MAX;
          }
          else
          {
            return INT_MIN;
          }
        }
        res = res*10 + no;
        i++;
      }
      return res*sign;
        
    }
};