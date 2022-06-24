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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
      unordered_map<int,int> m;
      for(int i = 0;i<postorder.size();i++)
      {
        m[postorder[i]] = i;
      }
      return build(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,m);
        
    }
  TreeNode* build(vector<int>& pre,int preStart, int preEnd,vector<int>& post,int postStart, int postEnd, unordered_map<int,int>& m)
  {
    TreeNode* root = new TreeNode(pre[preStart]);
    if(preStart==preEnd) return root;
    int postRoot = m[pre[preStart+1]]; //2
    int len = postRoot-postStart+1;
    cout<<len<<" \n";
    root->left = build(pre,preStart+1,preStart+len,post,postStart,postStart+len-1,m);
    // 1,4,0,2
    if(postRoot+1==postEnd) return root;
    root->right = build(pre,preStart+len+1,preEnd,post,postRoot+1,postEnd-1,m);
    return root;
  }
};