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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return build(preorder,0,preorder.size()-1);
    
  }
  TreeNode* build(vector<int> & preorder,int left,int right)
  {
    if(left>right) return NULL;
    TreeNode* root = new TreeNode(preorder[left]);
    int index = right+1;
    for(int i = left;i<=right;i++)
    {
      if(preorder[i]>preorder[left])
      {
        index = i;
        break;
      }
    }
    root->left = build(preorder,left+1,index-1);
    root->right = build(preorder,index,right);
    return root;
  }
  
  
};
/*



  
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      return build(preorder,0,preorder.size()-1);   
    }
  TreeNode* build(vector<int> & pre, int a ,int b)
  {
    if(a>b) return NULL;
    TreeNode* root= new TreeNode(pre[a]);
    int index = b+1;
    for(int i = a;i<=b;i++)
    {
      if(pre[i]>root->val)
      {
        index = i;
        break;
      }
    }
    root->left = build(pre,a+1,index-1);
    root->right = build(pre,index,b);
    return root;
  }
};
*/