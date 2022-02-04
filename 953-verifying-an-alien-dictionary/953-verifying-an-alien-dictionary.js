/**
 * @param {string[]} words
 * @param {string} order
 * @return {boolean}
 */
var isAlienSorted = function(words, order) {
    
       
        for(let i = 0; i < words.length- 1; i++)
        {
            
            let word1 = words[i]; 
            let word2 = words[i + 1]; 
            
            let l = 0; 
            let r = 0; 
            
            while(word1[l] == word2[r] && l < word1.length && r < word2.length)
            {
                l++; 
                r++; 
            }
            
            
//             int index1 = order.find(word1[l]); 
//             int index2 = order.find(word2[r]); 
            
            let index1 = -1; 
            for(let c = 0; c <  order.length; c++)
            {
                 if(order[c] == word1[l])
                     {
                         index1 = c; 
                         break; 
                     }
                
            }
            
                let index2 = -1; 
            for(let c = 0; c < order.length; c++)
            {
                 if(order[c] == word2[r])
                     {
                         index2 = c; 
                         break; 
                     }
                
            }

            
            if(index1 > index2)
            {
                return false; 
            }            
            
        }
        
        return true; 
    
};