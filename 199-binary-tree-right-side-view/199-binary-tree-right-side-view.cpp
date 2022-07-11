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
  int maxlevel = 0;
  vector<int> res;
  vector<int> rightSideView(TreeNode* root) {
    rec(root,1);
    return res;
    
    
  }
  void rec(TreeNode* root, int level)
  {
    if(root==NULL) return;
    if(level>maxlevel)
    {
      res.push_back(root->val);
      maxlevel = level;
    }
    rec(root->right,level+1);
    rec(root->left,level+1);
  }
};/*
  vector<int> rightSideView(TreeNode* root) {
    if(root==NULL) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    vector<int> temp;
    while(!q.empty())
    {
      temp.clear();
      int count = q.size();
      for(int i = 0;i<count;i++)
      {
        TreeNode* curr=  q.front();
        q.pop();
        temp.push_back(curr->val);
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
      }
      res.push_back(temp[count-1]);
    }
    return res;
  }*/
  /*
  int maxlevel = 0;
  vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
      if(root==NULL) return res;
      rec(root,1);
      return res;  
    }
  void rec(TreeNode* root, int level)
  {
    if(root==NULL) return;
    if(level>maxlevel)
    {
      res.push_back(root->val);
      maxlevel = level;
    }
    rec(root->right,level+1);
    rec(root->left,level+1);
    
  }
  */
