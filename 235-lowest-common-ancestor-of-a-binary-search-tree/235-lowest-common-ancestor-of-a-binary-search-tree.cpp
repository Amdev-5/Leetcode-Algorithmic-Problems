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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val > p->val && root->val> q->val) return lowestCommonAncestor(root->left,p,q);
    else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right,p,q);
    else return root;
  }
};
  /*TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL) return NULL;
    if(root==p) return p;
    if(root==q) return q;
    TreeNode* left= lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);
    if(left==NULL) return right;
    if(right==NULL) return left;
    else return root;
    
  }
};
*/
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p || root==q)
      return root;
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);
    if(left==NULL)
      return right;
    else if(right==NULL)
      return left;
    else
      return root;
  }
};
*/
  /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left,p,q);
            
        }
        if(root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
        
    }
};
*/