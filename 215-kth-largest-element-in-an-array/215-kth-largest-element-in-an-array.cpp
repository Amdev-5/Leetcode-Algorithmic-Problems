class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      //min heap of size n-k+1
      priority_queue<int> pq;
      int sz = nums.size()-k+1;
      for(int i = 0;i<nums.size();i++)
      {
        pq.push(nums[i]);
        if(pq.size()>sz) pq.pop();
      }
      return pq.top();
        
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
        
    }
};