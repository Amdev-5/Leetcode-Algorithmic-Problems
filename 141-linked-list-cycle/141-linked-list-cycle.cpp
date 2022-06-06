/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      /*
      unordered_set<ListNode*> s;
      ListNode* l1 = head;
      while(l1!=NULL)
      {
        if(s.find(l1)!=s.end())
          return true;
        s.insert(l1);
        l1 = l1->next;
      }
      return false;
      */
      
        if(head==NULL)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL and fast->next->next!=NULL )
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
      
        
        }
        
    
    
};