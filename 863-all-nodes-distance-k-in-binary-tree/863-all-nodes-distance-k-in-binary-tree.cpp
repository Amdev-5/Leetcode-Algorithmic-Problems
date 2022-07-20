/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void mark_parent(TreeNode* root,unordered_map<TreeNode*, TreeNode*> & parent)
  {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
      auto x = q.front();
      q.pop();
      if(x->left)
      {
        parent[x->left] = x;
        q.push(x->left);
      }
      if(x->right)
      {
        parent[x->right] = x;
        q.push(x->right);
      }
    }
  }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      unordered_map<TreeNode*,TreeNode*> parent;
      mark_parent(root,parent);
      unordered_map<TreeNode*, bool> visited;
      queue<TreeNode*> q;
      q.push(target);
      visited[target] = true;
      int curr_level = 0;
      while(!q.empty())
      {
        if(curr_level==k) break;
        curr_level++;
        int size = q.size();
        for(int i = 0;i<size;i++)
        {
          auto x = q.front();
          q.pop();
          if(x->left!=NULL && visited[x->left]!=true)
          {
            q.push(x->left);
            visited[x->left] = true;
          }
          if(x->right!=NULL && visited[x->right]!=true)
          {
            q.push(x->right);
            visited[x->right] = true;
          }
          if(parent[x]!=NULL && visited[parent[x]]!=true)
          {
            q.push(parent[x]);
            visited[parent[x]] = true;
          }
        }
      }
      vector<int> ans;
      while(!q.empty())
      {
        auto x = q.front();
        q.pop();
        ans.push_back(x->val);
      }
      return ans;
      
        
    }
};