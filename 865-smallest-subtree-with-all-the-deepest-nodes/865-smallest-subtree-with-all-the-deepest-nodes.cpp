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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      vector<TreeNode*> v;
      v.push_back(root);
      while(!q.empty())
      {
        v.clear();
        int count = q.size();
        for(int i = 0;i<count;i++)
        {
          TreeNode* curr = q.front();
          q.pop();
          v.push_back(curr);
          if(curr->left!=NULL)
            q.push(curr->left);
          if(curr->right!=NULL)
            q.push(curr->right);
        }
      }
      TreeNode* res = v[0];
      if(v.size()==1)
        return v[0];
      else
      {
        for(int i = 1;i<v.size();i++)
        {
          res = lca(root,v[i],res);
        }
      }
      return res;
        
    }
  TreeNode* lca(TreeNode* root,TreeNode* l1, TreeNode* l2)
  {
    if(root==NULL || root==l1 || root==l2)
      return root;
    TreeNode* left = lca(root->left,l1,l2);
    TreeNode* right = lca(root->right,l1,l2);
    if(left==NULL) return right;
    if(right==NULL) return left;
    else
      return root;
    
  }
};
/* find last level of tree if it contain 1 element return that if it contains 2 elements find lca of both */