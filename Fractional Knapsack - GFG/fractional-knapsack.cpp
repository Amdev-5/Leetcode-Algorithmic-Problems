// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool cmp(Item a,Item b)
{
    double x=(double)a.value/(double)a.weight;
    double y=(double)b.value/(double)b.weight;
    if(x>y) return true;
    else return false;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        /*for(int i = 0;i<n;i++)
        {
            cout<<arr[i].weight<<" "<<arr[i].value<<" ";
        }
        */
        double sum = 0.0;
        double wei = 0.0;
        for(int i = 0;i<n;i++)
        {
            if(wei>=W) break;
            if(wei+arr[i].weight<=W)
            {
                sum=sum+arr[i].value;
                wei+=arr[i].weight;
            }
            else if(wei<W)
            {
                double d = (double)arr[i].value/(double)arr[i].weight;
                sum=sum+(W-wei)*d;
                wei = W;
            }
        }
        return sum;
        // 10/60 20/100 30/120
        //sort  1/6 1/5 1/4
        // 60 +100 + 80
        // Your code here
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends