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
    int deepestLeavesSum(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      vector<int> v;
      while(!q.empty())
      {
        int count = q.size();
        v.clear();
        for(int i = 0;i<count;i++)
        {
          TreeNode* temp= q.front();
          q.pop();
          v.push_back(temp->val);
          if(temp->left!=NULL)
            q.push(temp->left);
          if(temp->right!=NULL)
            q.push(temp->right);
        }
      }
      int res = 0;
      for(int i = 0;i<v.size();i++)
      {
        res+=v[i];
      }
      return res;
      
        
    }
};