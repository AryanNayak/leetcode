class Solution {
    public String removeDuplicates(String s) {
        
        Stack<Character> stack = new Stack<>(); 
        
        for(int i = 0; i < s.length(); i++)
        {
            
            if(!stack.isEmpty() && stack.peek() == s.charAt(i))
            {
                stack.pop(); 
                continue; 
            }
            stack.push(s.charAt(i)); 
        }
        
        StringBuilder ans = new StringBuilder(); 
        
       for(char ch: stack)
        {
            ans.append(ch); 
        }
        
        return ans.toString(); 
    }
}