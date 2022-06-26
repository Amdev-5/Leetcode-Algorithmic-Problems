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
    TreeNode* recoverFromPreorder(string S) {
      stack<TreeNode*> stk;
      for(int i = 0;i<S.size();)
      {
        int level = 0;
        while(S[i]=='-') ++level,++i;
        int start = i;
        while(isdigit(S[i])) ++i;
        int val = stoi(S.substr(start,i-start+1));
        TreeNode* tmp = new TreeNode(val);
        if(stk.empty()) {stk.push(tmp);continue; }
        while(stk.size()!=level)
        {
          stk.pop();
        }
        if(stk.top()->left==NULL) stk.top()->left = tmp;
        else stk.top()->right = tmp;
        stk.push(tmp);
      }
      while(stk.size()>1)
        stk.pop();
      return stk.top();
      
    
      
    }
    

};
/*
vector
1
401
349 88
90
while()
*/