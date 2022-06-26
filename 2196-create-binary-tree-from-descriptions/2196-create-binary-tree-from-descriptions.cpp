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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
      unordered_map<int,TreeNode*> m;
      unordered_map<int,bool> isChild;
      for(auto &t: d)
      {
        if(m.count(t[0])==0){
          TreeNode* root = new TreeNode(t[0]);
          m[t[0]] = root;
        }
        if(m.count(t[1])==0)
        {
          TreeNode* root = new TreeNode(t[1]);
          m[t[1]] = root;
        }
        if(t[2]==1) m[t[0]]->left= m[t[1]];
        else m[t[0]]->right = m[t[1]];
        isChild[t[1]] = true;
      }
      TreeNode* res = NULL;
      for(auto &t: d)
      {
        if(isChild[t[0]]!=true)
        {
          res = m[t[0]];
          break;
        }
      }
      return res;
      
    }
};