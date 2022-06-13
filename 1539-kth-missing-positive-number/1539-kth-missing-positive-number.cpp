class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      int counter  = 1;
      int i = 0;
      while(i<arr.size())
      {
        if(k==0) return counter-1;
        if(arr[i]==counter)
        {
          counter++;
          i++;
        }
        else
        {
          k--;
          counter++;
        }
      }
      while(k>0)
      {
        counter++;
        k--;
      }
      return counter-1;
        
    }
};