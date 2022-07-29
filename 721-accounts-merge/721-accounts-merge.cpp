class Solution {
private:
	map<string,bool> visited;
	map<string,set<string> > graph;
public:
	void dfs(string email, set<string>& emailSet)
	{
		if(visited[email] == true) return;
		visited[email] = true;
		emailSet.insert(email);
		for(auto e: graph[email])
		{
			dfs(e, emailSet);
		}
	}

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		int n = accounts.size();
		map<string,string> emailToName;
		
        //create graph - 
		//connect edges from first email to all others
		for(int i=0; i<n; i++)
		{
			string firstEmail = accounts[i][1];
            emailToName[firstEmail] = accounts[i][0];
            visited[firstEmail] = false;
            for(int j=2; j<accounts[i].size();j++)
            {
                graph[accounts[i][j]].insert(firstEmail);
                graph[firstEmail].insert(accounts[i][j]);
                emailToName[accounts[i][j]] = accounts[i][0];
                visited[accounts[i][j]] = false;
            }
		}
		
		//for every account, do dfs, update visited and add to ans
		vector<vector<string>> ans;
		map<string,set<string> >::iterator it;
		for(int i=0; i<n; i++)
		{
			for(int j=1; j<accounts[i].size(); j++)
			{
				if(visited[accounts[i][j]] == false)
				{
					set<string> emailSet;
					dfs(accounts[i][j], emailSet);
					vector<string> temp(emailSet.begin(), emailSet.end());
					temp.insert(temp.begin(),emailToName[accounts[i][j]]);
					ans.push_back(temp);
				}
			}
		}

		return ans;
    }
};