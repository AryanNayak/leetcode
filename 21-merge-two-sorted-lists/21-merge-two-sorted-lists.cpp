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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == nullptr || l2 == nullptr)
        {
            return l1 == nullptr ? l2 : l1; 
        }
        
        
        ListNode* dummy = new ListNode(-1); 
        
        ListNode* prev = dummy; 
        
        
        while(l1 != nullptr && l2 != nullptr)
        {
            
            if(l1->val < l2->val)
            {
                prev->next = l1; 
                l1 = l1->next; 
            }
            else
            {
                prev->next = l2; 
                l2 = l2->next; 
            }
            prev = prev->next; 
        }
        
        
        if(l1 != nullptr)
        {
            prev->next = l1; 
        }
        else if(l2 != nullptr)
        {
            prev->next = l2; 
        }
    
        return dummy->next; 
        
    }
};