class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        auto comp = [r0, c0](vector<int> &a, vector<int> &b)
        {
            return abs(a[0]-r0) + abs(a[1]-c0) > abs(b[0]-r0) + abs(b[1]-c0);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

        for(int i=0 ; i<R ; i++)
        {
            for(int j=0; j<C ; j++)
            {
                minHeap.push({i, j});
            }
        }
        
        vector<vector<int>> resp;
        while(!minHeap.empty())
        {
            resp.push_back(minHeap.top());
            minHeap.pop();
        }        
                            
        return resp;
    }
};