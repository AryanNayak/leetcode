class Solution {
    public int firstUniqChar(String s) {
           HashMap<Character, Integer> answer = new HashMap<Character, Integer>();    
        for ( int i = 0; i < s.length(); i++){
            answer.put(s.charAt(i), answer.getOrDefault(s.charAt(i), 0) +1);
        }
        for ( int i = 0; i < s.length(); i++){
            if (answer.get(s.charAt(i)) == 1)
            return i;
        }
        return -1;
    }
}