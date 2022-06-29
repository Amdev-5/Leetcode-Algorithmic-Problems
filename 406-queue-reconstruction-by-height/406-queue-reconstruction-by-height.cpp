class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      sort(people.begin(),people.end(),[](const vector<int> & a, const vector<int> & b){
        return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);
      });
      vector<vector<int>> res;
      for(auto person: people)
      {
        res.insert(res.begin()+person[1],person);
      }
      return res;
    }
};
/*
sort 
[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]

now insert in res according to how many bigger height person needed in front res.begin()+person[1],person

*/