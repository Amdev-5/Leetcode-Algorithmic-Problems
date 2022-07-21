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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int m = left;
        int n = right;
        ListNode* dummy = new ListNode(-1), *pre = dummy,*curr;
        dummy->next = head;
        for(int i = 0;i<m-1;i++)
        {
            pre = pre->next;
        }
        curr = pre->next;
        for(int i = 0;i<n-m;i++)
        {
            ListNode* temp = curr->next;
            curr->next=curr->next->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }
        
        
};