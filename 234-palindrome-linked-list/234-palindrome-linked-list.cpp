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
    bool isPalindrome(ListNode* head) {
      vector<int> v;
      ListNode* l1 = head;
      while(l1!=NULL)
      {
        v.push_back(l1->val);
        l1 = l1->next;
      }
      int i = 0;
      int j = v.size()-1;
      while(i<j)
      {
        if(v[i]!=v[j])
          return false;
        i++;
        j--;
      }
      return true;
      /*
       //find the middle of linked list reverse elements after the middle give a pointer to head and one pointer to first element of reversed second half linked list compare values one by one
        if(head==NULL || head->next== NULL)
        {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast  = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow  = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverselist(slow->next);
        ListNode* curr = head;
        while(rev!=NULL)
        {
            if(rev->val!=curr->val)
            {
                return false;
            }
            rev = rev->next;
            curr = curr->next;
        }
        return true;
        
        
            
        
    }
    private:
    ListNode* reverselist(ListNode* head)
    {
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr!=NULL){
        ListNode *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
    */
    }
};