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
    bool isCousins(TreeNode* root, int x, int y) {
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        int count = q.size();
        bool found1 = false;
        bool found2 = false;
        for(int i=0;i<count;i++)
        {
          TreeNode* curr = q.front();
          q.pop();
          if(curr->val==x) found1 = true;
          if(curr->val==y) found2 = true;
          if(curr->left && curr->right)
          {
            if((curr->left->val==x && curr->right->val==y) || (curr->left->val==y && curr->right->val==x)) return false;
          }
          if(curr->left!=NULL) q.push(curr->left);
          if(curr->right!=NULL) q.push(curr->right);
        }
        if(found1 && found2) return true;
      }
      return false;
    }
};