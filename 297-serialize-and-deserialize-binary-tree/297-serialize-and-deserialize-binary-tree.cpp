/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  string serialize(TreeNode* root) {
    if(!root) return "";
    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
      TreeNode* curr = q.front();
      q.pop();
      if(curr==NULL) s.append("#,");
      else
      {
        s.append(to_string(curr->val)+',');
        if(curr!=NULL)
        {
          q.push(curr->left);
          q.push(curr->right);
        }
      }
    }
    return s;
    
  }
  TreeNode* deserialize(string data){
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
      TreeNode* node  = q.front();
      q.pop();
      
      getline(s,str,',');
      if(str=="#"){
        node->left=NULL;
      }
      else
      {
        TreeNode* leftNode = new TreeNode(stoi(str));
        node->left = leftNode;
        q.push(leftNode);
      }
      
      getline(s,str,',');
      if(str=="#"){
        node->right=NULL;
      }
      else
      {
        TreeNode* rightNode = new TreeNode(stoi(str));
        node->right = rightNode;
        q.push(rightNode);
      }
      
    }
    return root;
    
  }
};
  
  /*

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root== nullptr) return "#";
      return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
      
        
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      return mydeserialize(data);
    }
  TreeNode* mydeserialize(string& data){
    if(data[0]=='#')
    {
      if(data.size()>1) data = data.substr(2);
      return nullptr;
    }
    else{
      TreeNode* node = new TreeNode(helper(data));
      node->left = mydeserialize(data);
      node->right = mydeserialize(data);
      return node;
      
    }
  }
  private:
    int helper(string& data){
      int pos = data.find(',');
      int val = stoi(data.substr(0,pos));
      data = data.substr(pos+1);
      return val;
    }
 
};


 Your Codec object will be instantiated and called as such:
 Codec ser, deser;
 TreeNode* ans = deser.deserialize(ser.serialize(root));
*/