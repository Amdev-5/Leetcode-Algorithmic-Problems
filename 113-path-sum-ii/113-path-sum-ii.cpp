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
  vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<int> temp;
      dfs(root,targetSum,temp);
      return res; 
    }
  void dfs(TreeNode* root,int targetSum,vector<int>& temp)
  {
    if(root==NULL) return;
    //if(targetSum<0) return;
    if(targetSum==root->val && root->left==NULL && root->right==NULL)
    {
      temp.push_back(root->val);
      res.push_back(temp);
      temp.pop_back();
      return;
    }
    temp.push_back(root->val);
    dfs(root->left,targetSum-root->val,temp);
    dfs(root->right,targetSum-root->val,temp);
    temp.pop_back();
  }
};