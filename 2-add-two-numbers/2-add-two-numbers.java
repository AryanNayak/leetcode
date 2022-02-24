/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
         if(l1 == null || l2 == null)
        {
            return l1 == null ? l2 : l1; 
        }
        
        ListNode dummy = new ListNode(-1);
        ListNode prev = dummy; 
        int carry = 0; 
        ListNode p1 = l1, p2 = l2; 
        while(p1 != null || p2 != null || carry != 0)
        {
            int sum = 0;
            if(p1 != null)
            {
                sum += p1.val;
                p1 = p1.next; 
            }

            if(p2 != null)
            {
                sum += p2.val;
                p2 = p2.next;  
            }

        sum += carry; 

        carry = sum/10; 

        ListNode node = new ListNode(sum%10);
        prev.next = node;
        prev = prev.next;
        }

        return dummy.next; 
    }
}