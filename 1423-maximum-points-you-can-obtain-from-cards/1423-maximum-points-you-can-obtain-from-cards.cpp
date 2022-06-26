class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int total_pts = 0;
      for(int i = 0;i<cardPoints.size();i++)
      {
        total_pts+=cardPoints[i];
      }
      if(k==cardPoints.size()) return total_pts;
      int ans = 0;
      int curr = 0;
      int start = 0;
      int end = 0;
      k = cardPoints.size()-k;
      for(;end<cardPoints.size();end++)
      {
        curr+=cardPoints[end];
        if(end-start+1==k)
        {
          ans = max(ans,total_pts-curr);
          if(end!=cardPoints.size()-1)
          {
            curr-=cardPoints[start];
            start++;
            
          }
        }
      }
      ans = max(ans,total_pts-curr);
      return ans;
        
    }
};
