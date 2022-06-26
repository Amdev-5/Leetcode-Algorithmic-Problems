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
  vector<int> nums;
    TreeNode* increasingBST(TreeNode* root) {
      dfs(root);
      TreeNode* res = new TreeNode(nums[0]);
      TreeNode* curr = res;
      if(nums.size()==1) return res;
      for(int i = 1;i<nums.size();i++)
      {
        TreeNode* temp = new TreeNode(nums[i]);
        curr->right = temp;
        curr = temp;
      }
      return res;
      
      
        
    }
  void dfs(TreeNode* root)
  {
    if(root==NULL) return;
    dfs(root->left);
    nums.push_back(root->val);
    dfs(root->right);
  }
  
};