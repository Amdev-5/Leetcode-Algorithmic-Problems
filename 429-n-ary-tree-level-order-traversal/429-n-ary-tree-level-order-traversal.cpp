/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return {};
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int count = q.size();
            for(int i = 0;i<count;i++)
            {
                Node* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                for(Node* child:curr->children)
                {
                    q.push(child);
                }
            }
            res.push_back(temp);
        }
        return res;
        
        
    }
};