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
  int minDiffInBST(TreeNode* root) {
    int res = INT_MAX;
    int pre = -1;
    helper(root,res,pre);
    return res;
    
  }
  void helper(TreeNode* root, int & res, int& pre)
  {
    if(root)
    {
      helper(root->left,res,pre);
      if(pre!=-1)
      {
        res = min(res,root->val-pre);
      }
      pre = root->val;
      helper(root->right,res,pre);
    }
    
  }
};
/*
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> vec;
        while(!q.empty())
        {
            int count = q.size();
            for(int i = 0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                vec.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        sort(vec.begin(),vec.end());
        int res = INT_MAX;
        for(int i = 0;i<vec.size()-1;i++)
        {
            if(vec[i+1]-vec[i]<res)
                res = vec[i+1]-vec[i];
        }
        return res;
        
        
    }
};
*/