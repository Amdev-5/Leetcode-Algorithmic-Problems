class Solution {
public:
    bool evensum(int n){
        int sum=0;
        while(n){
            int t=n%10;
            sum+=t;
            n/=10;
        }
        return sum%2==0;
    }
    int countEven(int num) {
        int ans=0;
        for(int i=1;i<=num;i++){
            if(evensum(i))ans++;
        }
        return ans;
    }
};