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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
         if(head == nullptr || head->next == nullptr)
         {
             return nullptr;
         }

        ListNode* c1 = head; 
        ListNode* c2 = head; 
        
        
        int k = n; 
        
        while(k--)
        {
            c1 = c1->next;
        }
        
        if(c1 == nullptr)
            return head->next;
        while(c1->next != nullptr)
        {
            c1 = c1->next; 
            c2 = c2->next; 
        }
        
        
        c2->next = c2->next->next; 
        
        return head; 
        
    }
};