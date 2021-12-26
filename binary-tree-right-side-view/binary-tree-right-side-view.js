/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
      // kickstart with queue [root]
    // while loop
    // counter for current size of the queue
    // push only child which is children[length -1]

    const queue = [root]
    const results = []
    
    if(root == null)
        return results

    while(queue.length != 0) {
        let counter = queue.length

    for(let i = 0; i < counter; i++)
    {        // dequeue
        const first = queue.shift()

        // push to results
        if(i === counter - 1) {
            results.push(first.val) // all the levels -> last element -> we want
        }

        // enqueue child
        if(first.left) {
            queue.push(first.left)
        }

        if(first.right) {
            queue.push(first.right)
        }
    }

    }

    return results
};