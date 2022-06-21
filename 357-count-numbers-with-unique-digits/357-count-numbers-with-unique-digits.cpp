class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
      if(n>10) return 0;
      if(n==0) return 1;
      int sum = 1;
      if(n>0)
      {
        int end = (n>10)? 10: n;
        for(int i = 0;i<end;i++)
        {
          sum+=9*permutation(9,i);
        }
      }
      return sum;
      
    }
  int permutation(int n,int r)
  {
    if(r==0)
      return 1;
    else
      return n* permutation(n-1,r-1);
  }
};
// A(n) = P(10,n)-P(9,n-1)  = 9* P(9,n-1)
//return sum of A(0)+A(1).... n or 10
