class Solution {
    public int maximum69Number (int num) {
        
        String str = Integer.toString(num); 
        
        char[] arr = str.toCharArray(); 
        
        for(int i =0; i < arr.length; i++)
        {
            if(arr[i] == '6')
            {
                arr[i] = '9';
                break;
            }
        }
        
        str = String.valueOf(arr); 
        
        return Integer.parseInt(str); 
    }
}