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
    int rob(TreeNode* root) {
      if(root->left==NULL && root->right==NULL) return root->val;
      int l,r;
      return rec(root,l,r);
      
        
    }
  int rec(TreeNode* root,int & l,int & r)
  {
    if(root==NULL) return 0;
    int ll = 0,lr = 0,rl = 0,rr = 0;
    l = rec(root->left,ll,lr);
    r = rec(root->right,rl,rr);
    return max(root->val+ll+lr+rl+rr,l+r);
    
  }
};