class Solution {
public:
    int removePalindromeSub(string s) {
      int count_a = 0;
      int count_b = 0;
      bool is_palindrome = true;
      int n = s.size();
      for(int i=0;i<n;i++)
      {
        if(s[i]!=s[n-1-i]) is_palindrome = false;
        if(s[i]=='a')
          count_a++;
        else
          count_b++;
      }
      if(is_palindrome) return 1;
      return 2;
        
    }
};