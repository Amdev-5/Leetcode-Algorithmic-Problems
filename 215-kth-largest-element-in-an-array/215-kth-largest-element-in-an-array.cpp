class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        /*
        stack<int> st;
        st.push(nums[0]);
        int i = 1;
        while(i<n)
        {
            st.push(nums[i]);
            i++;
        }
        if(st.size()<k)
        {
            return st.top();
        }
        else
        {
            while(k!=1)
            {
                st.pop();
                k--;
            }
        }
        
        return st.top();
        */
        int zc = nums[n-k];
        return zc;
        
    }
};