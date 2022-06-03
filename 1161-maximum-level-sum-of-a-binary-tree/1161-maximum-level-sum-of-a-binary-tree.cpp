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
    int maxLevelSum(TreeNode* root) {
      int level = 0;
      int maxlevel = 1;
      int maxi = root->val;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        level++;
        int count = q.size();
        int temp = 0;
        for(int i = 0;i<count;i++)
        {
          TreeNode* curr= q.front();
          q.pop();
          temp+=curr->val;
          if(curr->left!=NULL)
            q.push(curr->left);
          if(curr->right!=NULL)
            q.push(curr->right);
        }
        if(temp>maxi)
        {
          maxlevel = level;
          maxi = temp;
        }
      }
      return maxlevel;
      
        
    }
};