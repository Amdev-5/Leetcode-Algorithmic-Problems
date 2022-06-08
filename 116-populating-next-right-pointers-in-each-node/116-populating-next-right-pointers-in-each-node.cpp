/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      if(root==NULL) return NULL;
      queue<Node*> q;
      q.push(root);
      //vector<Node*> v;
      Node* temp = root;
      while(q.size())
      {
        //v.clear();
        int count = q.size();
        for(int i = 0;i<count;i++)
        {
          Node* curr = q.front();
          q.pop();
          //v.push_back(curr);
          if(i==0) temp = curr;
          else
          {
            if(i==count-1) curr->next = NULL;
            if(i!=0) temp->next = curr, temp = curr; 
          }
          if(curr->left!=NULL) q.push(curr->left);
          if(curr->right!=NULL) q.push(curr->right);
        }
      }
      return root;
        
    }
};