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
ListNode *dummy = new ListNode(0), *pre = dummy;
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        dummy -> next = head;
        int len = length(head);
        for (int i = 0; i < len / k; i++) {
            for (int j = 1; j < k; j++) {
                ListNode* temp = pre -> next;
                pre -> next = head -> next;
                head -> next = head -> next -> next;
                pre -> next -> next = temp;
            }
            pre = head;
            head = head -> next;
        }
        return dummy -> next;
    }    

    int length(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head -> next;
        }
        return len;
    }
};