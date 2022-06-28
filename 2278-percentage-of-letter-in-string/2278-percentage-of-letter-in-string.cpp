class Solution {
public:
    int percentageLetter(string s, char letter) {
      long n = s.length();
        long cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == letter)
                cnt++;
        }
        
        long x = cnt* 100 / n;
        
        return (int)x;
        
    }
};