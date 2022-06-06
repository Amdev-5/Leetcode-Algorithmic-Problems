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
    ListNode *detectCycle(ListNode *head) {
      unordered_set<ListNode*> s;
      ListNode* l1 = head;
      while(l1!=NULL)
      {
        if(s.find(l1)!=s.end())
          return l1;
        s.insert(l1);
        l1 = l1->next;
      }
      return  NULL;
        
    }
};