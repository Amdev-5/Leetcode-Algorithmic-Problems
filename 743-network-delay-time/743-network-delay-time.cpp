class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> res(n+1,INT_MAX);
        res[k] = 0;
        for(int i = 0;i<n-1;i++)
        {
            for(int j = 0;j<times.size();j++)
            {
                if(res[times[j][0]]!=INT_MAX && res[times[j][0]]+times[j][2] < res[times[j][1]])
                {
                    res[times[j][1]] = res[times[j][0]]+times[j][2];
                }
                
            }
        }
        
        int z = INT_MIN;
        for(int i = 1;i<=n;i++)
        {
            if(res[i]>z)
                z = res[i];
        }
        if(z==INT_MAX)
                return -1;
        return z;
        
        
    }
};