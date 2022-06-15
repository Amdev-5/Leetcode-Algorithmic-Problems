// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
vector<int> res;
    vector<int> subsetSums(vector<int> arr, int N)
    {
        rec(arr,N,0);
        return res;
        // Write Your Code here
    }
    void rec(vector<int> arr,int N,int sum)
    {
        if(N==0)
        {
            res.push_back(sum);
        }
        else
        {
            rec(arr,N-1,sum);
            rec(arr,N-1,sum+=arr[N-1]);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends