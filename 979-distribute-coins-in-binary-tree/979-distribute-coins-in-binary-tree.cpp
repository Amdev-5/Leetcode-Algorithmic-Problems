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
/*We traverse childs first (post-order traversal), and return the ballance of coins. For example, if we get '+3' from the left child, that means that the left subtree has 3 extra coins to move out. If we get '-1' from the right child, we need to move 1 coin in. So, we increase the number of moves by 4 (3 moves out left + 1 moves in right). We then return the final ballance: r->val (coins in the root) + 3 (left) + (-1) (right) - 1 (keep one coin for the root).
*/
class Solution {
public:
  int steps= 0;
  int coins(TreeNode* root)
  {
    if(root==NULL) return 0;
    int l = coins(root->left);
    int r = coins(root->right);
    steps+= abs(l)+ abs(r);
    return (l+r + root->val -1);
  }
    int distributeCoins(TreeNode* root) {
      coins(root);
      return steps;
        
    }
};