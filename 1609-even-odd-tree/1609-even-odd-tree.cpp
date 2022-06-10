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
    bool isEvenOddTree(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      int level = 0;
      int prev = 0;
      while(!q.empty())
      {
        int count = q.size();
        for(int i = 0;i<count;i++)
        {
          TreeNode* curr = q.front();
          q.pop();
          if(level%2==0 && (curr->val%2==0 || (i>0 && curr->val<=prev))) return false;
          if(level%2!=0 && (curr->val%2!=0 || (i>0 && curr->val>=prev))) return false;
          prev = curr->val;
          if(curr->left!=NULL) q.push(curr->left);
          if(curr->right!=NULL) q.push(curr->right);
        }
        level++;
        
      }
      return true;
        
    }
};