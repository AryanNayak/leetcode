/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {

    // preorder dfs

    //MLR
    const output= []

    dfs(root, output)

    function dfs(root, output) {
        if(root === null){
            output.push("null") 
            return
        } 

        output.push(root.val)
        dfs(root.left, output)
        dfs(root.right, output)
    }

    console.log(String(output))

    return String(output)
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    // split by ,
    // new Node(value)
    const elements = data.split(',')
    //const output = new TreeNode()



    let i = 0
    // let root = null

    const node = dfs(elements)

    function dfs(output) {
        if(i < elements.length && output[i] === "null"){
            i++;
            return null; 
        } 

        const root = new TreeNode(output[i])// [2,3,4,null,]
        i++
        root.left = dfs(output)
        root.right = dfs(output)

        return root; 
    }


    return node; 

};

// function deserialize(str) {
//   // your code here
//   // string '1,2,null'
//   // split that into array
//   // loop through that array
//   // keep creating nodes
//   // const node = new Node(arr[i])
//   // keep adding left and right branch
//   // when we hit null, don't go any further 

//   const nodes = str.split(',')

//   let i = 0

//   function preorderDeserialize() {
//     if(nodes[i] === "null") {
//       i++ 
//       return null
//     }

//     const node = new Node(Number(nodes[i]))

//     i++

//     node.left = preorderDeserialize()
//     node.right = preorderDeserialize()

//     return node
//   }

//   return preorderDeserialize()
// }


/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */