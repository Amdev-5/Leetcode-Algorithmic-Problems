class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int mini = prices[0];
    int netprofit = 0;
    int profit = 0;
    int n = prices.size();
    for(int i = 0;i<prices.size();i++)
    {
      if(prices[i]<mini)
        mini = prices[i];
      profit = prices[i]-mini;
      netprofit = max(netprofit,profit);
    }
    return netprofit;
    
  }
};
