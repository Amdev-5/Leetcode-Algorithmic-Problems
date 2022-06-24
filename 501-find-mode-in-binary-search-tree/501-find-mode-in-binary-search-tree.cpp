/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  unordered_map<int,int> m;
  int mode = INT_MIN;
    vector<int> findMode(TreeNode* root) {
      dfs(root);
      vector<int> res;
      for(auto t: m)
      {
        if(t.second==mode)
          res.push_back(t.first);
      }
      return res;
      
    }
  void dfs(TreeNode* root)
  {
    if(root==NULL) return;
    m[root->val]++;
    mode = max(m[root->val],mode);
    dfs(root->left);
    dfs(root->right);
  }
};