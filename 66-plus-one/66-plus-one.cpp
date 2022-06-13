class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int carry = 1;
      int i = digits.size()-1;
      vector<int> res;
      while(i>=0)
      {
        int sum = digits[i]+carry;
        res.push_back(sum%10);
        carry = sum/10;
        i--;
      }
      if(carry)
      {
        res.push_back(carry);
      }
      reverse(res.begin(),res.end());
      return res;
    
        
    }
};