class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
      sort(courses.begin(),courses.end(),[](const vector<int> & a, const vector<int> & b)
           {
             return (a[1]<b[1] || (a[1]==b[1] && a[0]<b[0]));
           });
      priority_queue<int>pq;
      int counter = 0;
      for(auto& c: courses)
      {
        int t = c[0];
        int d = c[1];
        
        pq.push(t);
        counter+=t;
        
        if(counter>d)
        {
          counter-=pq.top();
          pq.pop();
        }
        
      }
      return pq.size();
    }
};
