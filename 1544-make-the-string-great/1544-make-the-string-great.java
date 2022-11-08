class Solution {
    public String makeGood(String s) {
        
        Stack<Character> stack = new Stack<>(); 
        
        for(char ch: s.toCharArray())
        {

        
            if(!stack.isEmpty() && Math.abs(stack.lastElement() - ch) == 32)
            {
                stack.pop();
            }
            else
            {
                stack.add(ch); 
            }
        }
        
        
        StringBuilder ans = new StringBuilder(); 
        
        for(char ch: stack)
        {
            ans.append(ch); 
        }
        
        
        return ans.toString(); 
    }
}