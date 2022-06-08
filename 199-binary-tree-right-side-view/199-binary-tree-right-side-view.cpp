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
  int maxlevel = 0;
  vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
      if(root==NULL) return res;
      rec(root,1);
      return res;  
    }
  void rec(TreeNode* root, int level)
  {
    if(root==NULL) return;
    if(level>maxlevel)
    {
      res.push_back(root->val);
      maxlevel = level;
    }
    rec(root->right,level+1);
    rec(root->left,level+1);
    
  }
};