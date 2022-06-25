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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      if(root==NULL) return {};
      vector<vector<int>> res;
      queue<TreeNode*> q;
      q.push(root);
      //res.push_back({root->val});
      while(!q.empty())
      {
        vector<int> temp;
        int count = q.size();
        for(int i =0;i<count;i++)
        {
          TreeNode* z = q.front();
          q.pop();
          temp.push_back(z->val);
          if(z->left!=NULL) q.push(z->left);
          if(z->right!=NULL) q.push(z->right);
        }
        res.push_back(temp);
      }
      reverse(res.begin(),res.end());
      return res;
        
    }
};