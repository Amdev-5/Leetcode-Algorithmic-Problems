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
    int kthSmallest(TreeNode* root, int k) {
      dfs(root);
      sort(nums.begin(),nums.end());
      return nums[k-1];
    }
  void dfs(TreeNode* root)
  {
    if(root==NULL) return;
    nums.push_back(root->val);
    dfs(root->left);
    dfs(root->right);
  }
};