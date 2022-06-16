class Solution {
public:
  /*
  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    solve(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
    
  }
  void solve(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }
};
*/
  // Optimal SOlution refer Striver video if doubt
    string getPermutation(int n, int k) {
      vector<int> temp;
      int fact = 1;
      for(int i = 1;i<n;i++)
      {
        fact = fact*i;
        temp.push_back(i);
      }
      temp.push_back(n);
      k = k-1;
      string res = "";
      while(true)
      {
        res = res+ to_string(temp[k/fact]);
        temp.erase(temp.begin()+ k/fact);
        if(temp.size()==0)
        {
          break;
        }
        k = k%fact;
        fact = fact/temp.size();
      }
      return res;
      
    
  }
};
