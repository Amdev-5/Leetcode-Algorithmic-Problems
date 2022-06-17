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
    // child of leaves should say we are covered
    if(root==NULL) return 1;
    
    // check left and right
    int lchild = minCameraCover_(root->left);
    int rchild = minCameraCover_(root->right);
    //if any of the child need camera then put camera and return 0 saying that camera has been implanted
    if(lchild==-1 || rchild==-1)
    {
      camera++;
      return 0;
    }
    // if any of child has camera then return 1 saying i am covered
    if(lchild==0 || rchild==0) return 1;
    // return otherwise or for the root (critical case)
    return -1;
  }
    int minCameraCover(TreeNode* root) {
      //this camera++ will happen for critical case with when root need to implant camera
      if(minCameraCover_(root)==-1) camera++;
      return camera;
    }
  
};