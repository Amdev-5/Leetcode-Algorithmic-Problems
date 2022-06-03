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
  unordered_map<int,int> m;
  int res = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
      rec(root);
      return res;
      
        
    }
  void rec(TreeNode* root)
  {
    if(root==NULL) return;
    m[root->val]++;
    if(!root->left && !root->right)
    {
      bool flag = false;
      for(auto t: m)
      {
        if(t.second%2!=0)
        {
          if(flag)
          {
            m[root->val]--;
            return;
          }
          else
          {
            flag = true;
          }
        }
      }
      res++;
      cout<<root->val;
      m[root->val]--;
    }
    else
    {
      //m[root->val]++;
      rec(root->left);
      rec(root->right);
      m[root->val]--;
    }
  }
  
};
//in andy path every number should occur in even times only one number can exist odd times
