class Solution {
public:
    int dp[(1<<16)+2];
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
        
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};  /* Backtracking 
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1)
            return true;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%k!=0 || k>nums.size())
            return false;
        sum/=k;
        int temp = sum;
        vector<bool> visited(nums.size(),false);
        return subsetsum(0,nums,visited,sum,k,temp);
        
    }
    bool subsetsum(int curr,vector<int>& nums,vector<bool>& visited,int sum,int k,int temp)
    {
        if(k==0)
        {
            return true;
        }
        if(temp<0)
            return false;
        if(temp==0)
        {
            return subsetsum(0,nums,visited,sum,k-1,sum);
        }
        for(int i = curr;i<nums.size();i++)
        {
            if(visited[i]==false)
            {
                visited[i] = true;
                if(subsetsum(i,nums,visited,sum,k,temp-nums[i]))
                    return true;
                visited[i] = false;
                
            }
        }
        return false;
        
    }
    
};
*/


