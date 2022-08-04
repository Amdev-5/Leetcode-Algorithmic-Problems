class Solution {
public:
    int mirrorReflection(int p, int q) {
      int a = __gcd(p,q);
      int lcm = (p*q)/a;
      cout<<lcm<<" ";
      int x = lcm/p;
      cout<<x<<" ";
      if(x%2==0) return 0;
      int count = lcm/q;
      if(count%2==0) return 2;
      return 1;
    }
};