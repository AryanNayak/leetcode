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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null)
            return head ;
        ListNode c1 = head;
        ListNode c2 = head;
        ListNode curr = head;

        int len = 0;

        while(curr != null) {
            len++;
            curr = curr.next;
        }

        k = k % len;

        while(k-- != 0) {
            c1 = c1.next;
        }

        if(c1 == null) {
            return head.next;
        }

        while(c1.next != null) {
            c1 = c1.next;
            c2 = c2.next;
        }
        c1.next = head;
        head = c2.next; 
        c2.next = null;

        return head;
    }
}