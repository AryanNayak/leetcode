/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var newList = new ListNode(0, null);
    var res = newList;

    var carry = 0;
    while(l1 || l2 || carry) {
        // 999888
        // 1
        var sum =0; 

        if(l1)
        {
            sum += l1.val; 
            l1 = l1.next; 
        }

        if(l2)
        {
            sum += l2.val;
            l2 = l2.next; 
        }

        sum += carry; 

        if(sum > 9) {
            carry = 1;
            newList.next = new ListNode(sum - 10, null);
        } else {
            carry = 0;
            newList.next = new ListNode(sum, null);
        }
        newList = newList.next;
    }

    return res.next;
};