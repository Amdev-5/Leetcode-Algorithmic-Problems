class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
      vector<vector<int>> adj(numCourses);
      vector<vector<bool>> isreach(numCourses,vector<bool>(numCourses,false));
      for(int i = 0;i<prerequisites.size();i++)
      {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        isreach[prerequisites[i][0]][prerequisites[i][1]] = true;
      }
      for(int k = 0;k<numCourses;k++)
      {
        for(int i = 0;i<numCourses;i++)
        {
          for(int j = 0;j<numCourses;j++)
          {
            if(isreach[i][k]==true && isreach[k][j]==true) isreach[i][j] = true;
          }
        }
      }
      vector<bool> res;
      for(int i = 0;i<queries.size();i++)
      {
        if(isreach[queries[i][0]][queries[i][1]]==true) res.push_back(true);
        else res.push_back(false);
      }
      return res;
    }
};