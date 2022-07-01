// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int modulo = 1000000007;
    long long countWays(int n)
    {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        for(int i = 1;i<=n;i++)
        {
            long long res = 0;
            for(int j =1;j<=3;j++)
            {
                if(i-j>=0)
                {
                    int subres= dp[i-j]%modulo;
                    if(subres!=-1)
                    {
                        res = ((res%modulo)+(subres%modulo))%modulo;
                        
                    }
                }
            }
            dp[i] = res;
        }
        return dp[n];
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends