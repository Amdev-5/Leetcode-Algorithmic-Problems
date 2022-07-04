class Solution {
public:
    int candy(vector<int>& ratings) {
      int n = ratings.size();
      vector<int> left(n,1);
      vector<int> right(n,1);
      int index = 0;
      //forward scan to make sure right boy having higher rating has more candies than left one
      for(int i=1;i<n;i++)
      {
        if(ratings[i]>ratings[i-1])
          left[i] = left[i-1]+1;
      }
      //backward scan to make sure left boy with higher ratings has more candies than left one
      for(int i =n-2;i>=0;i--)
      {
        if(ratings[i]>ratings[i+1])
          right[i] = right[i+1]+1;
      }
      //takin max of both to make sure any boy having higher rating than left and right has more candies 
      int res= 0;
      for(int i = 0;i<n;i++)
      {
        res+=max(left[i],right[i]);
      }
      return res;
      
      
        
    }
};


