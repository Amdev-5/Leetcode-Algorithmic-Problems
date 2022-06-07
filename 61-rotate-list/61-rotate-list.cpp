/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(k==0 || head==NULL) return head;
      ListNode* l1 = head;
      int count = 1;
      while(l1->next!=NULL) l1=l1->next,count++;
      l1->next = head;
      k=k%count;
      if(k)
      {
        for(int i = 0;i<count-k;i++)
          l1 = l1->next;
      }
      ListNode* res = l1->next;
      l1->next = NULL;
      return res;
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      /*
        if(head==NULL)
        {
            return NULL;
        }
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            n++;
            temp = temp->next;
        }
        k = k%n;
        if(k==0)
        {
            return head;
        }
        ListNode* new_first = head;
        int i = 1;
        while(i!=n-k)
        {
            i++;
            new_first = new_first->next;
            
        }
        ListNode* first = new_first->next;
        new_first->next= NULL;
        ListNode* counter = first;
        while(counter->next!=NULL)
        {
            counter = counter->next;
        }
        counter->next = head;
        return first;
*/
        
        
    }
};