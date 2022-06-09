class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
      int n = arr.size();
      int l = -1;
      for(int i = arr.size()-1;i>0;i--)
      {
        if(arr[i-1]>arr[i])
        {
          l = i-1;
          break;
        }
      }
      //find from right when an element is bigger first 
      //from rightward find an element that is biggest smaller element than this element
      if(l==-1) return arr;
      int r = l+1;
      for(int i = l+1;i<n;i++)
      {
        if(arr[i]<arr[l] && arr[i]>arr[r])
          r = i;
      }
      swap(arr[l],arr[r]);
      return arr;
    }
};