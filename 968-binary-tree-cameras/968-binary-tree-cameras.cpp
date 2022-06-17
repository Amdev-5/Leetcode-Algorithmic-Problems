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
  //0-camera
  //-1 need
  //1 covered
  int camera = 0;
  int minCameraCover_(TreeNode* root)
  {
    if(root==NULL) return 1;
    
    int lchild = minCameraCover_(root->left);
    int rchild = minCameraCover_(root->right);
    
    if(lchild==-1 || rchild==-1)
    {
      camera++;
      return 0;
    }
    if(lchild==0 || rchild==0) return 1;
    
    return -1;
  }
    int minCameraCover(TreeNode* root) {
      if(minCameraCover_(root)==-1) camera++;
      return camera;
    }
  
};