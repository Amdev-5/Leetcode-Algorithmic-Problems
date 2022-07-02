class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n,1e8);
        price[src] = 0;
        vector<int> temp(price);
        for(int i = 0;i<=k;i++)
        {
            
            for(int edge = 0;edge<flights.size();edge++)
            {
                temp[flights[edge][1]] = min(price[flights[edge][0]] + flights[edge][2] ,temp[flights[edge][1]] );
                     
            }
            price = temp;
        }
        if(price[dst]==1e8)
            return -1;
        return price[dst];
        
    }
};

/*
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int price[n];
        for(int i = 0;i<n;i++)
        {
            price[i] = INT_MAX;
        }
        price[0] = 0;
        queue<int> q;
        q.push(src);
        vector<pair<int,int>> adj[flights.size()];
        bool flag[n];
        for(int i = 0;i<n;i++)
        {
            flag[i] = false;
        }
        for(int i = 0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
            flag[flights[i][0]] = true;
        }
        while(!q.empty() && k>=0)
        {
            int u = q.front();
            q.pop();
            if(flag[u])
            {
                for(auto t: adj[u])
                {
                    if(price[u]+t.second < price[t.first])
                    {
                        price[t.first] = price[u] + t.second;
                        q.push(t.first);
                    }
                }
                
            }
            else
                return -1;
            k--;
        }
        if(price[dst]==INT_MAX)
            return -1;
        return price[dst];
        
    }
    */