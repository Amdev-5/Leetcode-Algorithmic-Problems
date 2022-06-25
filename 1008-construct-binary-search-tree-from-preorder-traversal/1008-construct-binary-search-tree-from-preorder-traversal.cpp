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
      //unordered_map<int,int> m;
      //for(int i = 0;i<preorder.size();i++) m[preorder[i]] = i;
      return build(preorder,0,preorder.size()-1);
      
      
        
    }
  TreeNode* build(vector<int> & pre, int a ,int b)
  {
    if(a>b) return NULL;
    TreeNode* root= new TreeNode(pre[a]);
    //if(a==b) return root;
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