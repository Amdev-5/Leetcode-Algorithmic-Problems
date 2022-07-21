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
  vector<int> helper(TreeNode* root, int& ans)
  {
    if(root==NULL) return {0,INT_MAX,INT_MIN};
    auto l = helper(root->left,ans);
    auto r = helper(root->right,ans);
    if(l[2]<root->val && r[1]>root->val)
    {
      ans = max(ans,l[0]+r[0]+root->val);
      return {l[0]+r[0]+root->val,min(root->val,l[1]),max(root->val,r[2])};
    }
    else
    {
      return {0,INT_MIN,INT_MAX};
    }
  }
    int maxSumBST(TreeNode* root) {
      int ans = 0;
      helper(root,ans);
      return ans;
      
      
        
    }
};