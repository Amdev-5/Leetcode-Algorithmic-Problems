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
  
  /*int height(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    
    return max(height(root->left), height(root->right))+1;
}
  
  vector<int> dist_k(TreeNode *root, int k, vector<int> v){
    if(root == NULL){
        return v;
    }
    if(k == 0){
        v.push_back(root->val);
        // cout<<root->key<<" ";
        return v;
    }
    v = dist_k(root->right, k-1, v);
    v = dist_k(root->left, k-1, v);
    return v;
}

*/
    vector<vector<int>> levelOrder(TreeNode* root) {
       /*int k = height(root);
      vector<vector<int>> x;
    for(int i = 0; i < k; i++){
        vector<int> v = dist_k(root, i, v);
      x.push_back(v);
    }
      return x;*/
      vector<vector<int>> result;
      if(root==NULL) return result;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        int count = q.size();
        vector<int> temp;
        for(int i = 0;i<count;i++)
        {
          TreeNode* z = q.front();
          q.pop();
          temp.push_back(z->val);
          if(z->left)
          {
            q.push(z->left);
          }
          if(z->right)
          {
            q.push(z->right);
          }
        }
        result.push_back(temp);
      }
      return result;
    }
};