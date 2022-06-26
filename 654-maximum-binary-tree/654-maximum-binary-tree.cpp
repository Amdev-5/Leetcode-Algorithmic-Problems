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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      unordered_map<int,int> m;
      for(int i = 0;i<nums.size();i++)
      {
        m[nums[i]] = i;
      }
      return build(nums,0,nums.size()-1,m);
        
    }
  TreeNode* build(vector<int>& nums,int start,int end,unordered_map<int,int>& m)
  {
    if(start>end) return NULL;
    int z=*max_element(nums.begin()+start,nums.begin()+end+1);
    //cout<<z<<" ";
    int index = m[z];
    TreeNode* root= new TreeNode(z);
    root->left = build(nums,start,index-1,m);
    root->right = build(nums,index+1,end,m);
    return root;
  }
};