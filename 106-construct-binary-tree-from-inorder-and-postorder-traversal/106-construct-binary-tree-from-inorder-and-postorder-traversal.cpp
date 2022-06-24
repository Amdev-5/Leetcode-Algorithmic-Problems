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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      unordered_map<int,int> m;
      for(int i = 0;i<inorder.size();i++) m[inorder[i]] = i;
      return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
    }
  TreeNode* build(vector<int> & in, int a, int b, vector<int>& post, int c,int d, unordered_map<int,int> & m)
  {
    if(a>b || c>d) return NULL;
    TreeNode* root = new TreeNode(post[d]);
    int index = m[post[d]];
    int numsLeft = index-a;
    root->left = build(in,a,index-1,post,c,c+numsLeft-1,m);
    root->right = build(in,index+1,b,post,c+numsLeft,d-1,m);
    return root;
    
  }
};
/*




*/