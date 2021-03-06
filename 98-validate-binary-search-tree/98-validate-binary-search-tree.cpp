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
  bool isValidBST(TreeNode* root) {
    //INT_MIN<root->val<INT_MAX
    // INT_MIN<root->left->val<root->val
    //root->val<root->right->val< INT_MAX
    //if(root->left==NULL && root->right==NULL) return true;
    return isBST(root,LONG_MIN,LONG_MAX);
    
  }
  bool isBST(TreeNode* root,long mini,long maxi)
  {
    if(root== NULL) return true;
    if(root->val<=mini || root->val>=maxi) return false;
    return (isBST(root->left,mini,root->val) && isBST(root->right,root->val,maxi));
  }
};
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
    bool isValidBST(TreeNode* root) {
      if(root->left==NULL && root->right==NULL) return true;
      return isValid(root,LONG_MIN,LONG_MAX);
    }
  bool isValid(TreeNode* root, long mini, long maxi)
  {
    if(root==NULL) return true;
    if(root->val>=maxi || root->val<=mini) return false;
    return isValid(root->left,mini,root->val) && isValid(root->right,root->val,maxi);
  
    
  }
};
*/