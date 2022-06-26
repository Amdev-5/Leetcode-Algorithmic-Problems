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
    int findSecondMinimumValue(TreeNode* root) {
      dfs(root);
      sort(nums.begin(),nums.end());
      if(nums.size()==1) return -1;
      for(int i =1;i<nums.size();i++)
      {
        if(nums[i]!=nums[i-1]) return nums[i];
      }
      return -1;
      
        
    }
  void dfs(TreeNode* root)
  {
    if(root==NULL) return;
    nums.push_back(root->val);
    dfs(root->left);
    dfs(root->right);
  }
};