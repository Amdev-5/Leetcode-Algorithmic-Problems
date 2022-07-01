class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> res;
        vector<int> indegree(n,0);
        for(int i = 0;i<graph.size();i++)
        {
            indegree[i]+= graph[i].size();
            for(int j = 0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
            } 
            
        }
        queue<int> q;
        for(int i = 0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int z = q.front();
            res.push_back(z);
            q.pop();
            for(int next: adj[z])
            {
                if(--indegree[next]==0)
                {
                    q.push(next);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
        
        
    }
};