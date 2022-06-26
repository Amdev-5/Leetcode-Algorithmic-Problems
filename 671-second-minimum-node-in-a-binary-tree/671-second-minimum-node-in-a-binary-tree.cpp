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
  int findSecondMinimumValue(TreeNode* root) {
    if(root==NULL) return -1;
    int first = root->val;
    return mini(root,first);
  }
  int mini(TreeNode* root, int first)
  {
    if(root==NULL) return -1;
    if(root->val!=first) return root->val;
    int left = mini(root->left,first);
    int right = mini(root->right,first);
    if(left==-1) return right;
    if(right==-1) return left;
    return min(left,right);
  }
};
  /*
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
*/