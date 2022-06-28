class Solution {
public:
    bool divideArray(vector<int>& nums) {
      sort(nums.begin(),nums.end());
    int count=0;
    int n=nums.size()/2;
    for(int i=0; i<2*n; i+=2){
        if(nums[i]==nums[i+1]){
            count++;
        }
    }
    if(count==n){
        return true;
    }
    return false;
        
    }
};