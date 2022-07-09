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
  int count = 0;
  int kthSmallest(TreeNode* root, int k) {
    stack<int> st;
    pre(root,st);
    while(count-k>0)
    {
      st.pop();
      count--;
    }
    return st.top();
    
    
    
  }
  void pre(TreeNode* root, stack<int>& st)
  {
    if(root==NULL) return;
    pre(root->left,st);
    st.push(root->val);
    count++;
    pre(root->right,st);
  }
};
  /*
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* p = root;
    while(p || !st.empty())
    {
      while(p)
      {
        st.push(p);
        p = p->left;
      }
      p = st.top();
      if(--k==0)
        return p->val;
      st.pop();
      p = p->right;
    }
    return 0;
  }
};
*/
  
  /*
  
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
*/