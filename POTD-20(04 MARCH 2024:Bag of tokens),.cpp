class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());              
        int s = 0;                                    
        int maxi = 0;                                   
        int l = 0, r = tokens.size() - 1;             
        while (l <= r) { 
            if (power >= tokens[l]) {               
                power -= tokens[l]; //if want to decrease power to increase score then decrease minimum token from left               
                s++;                             
                l++;                             
                maxi = max(maxi, s);             
            } 
            else if (s > 0) {                  
                power += tokens[r]; //if want to increase power so that it can be applied to increment score then increase by maximum token in the right         
                s--;                        
                r--;                        
            } 
            else {
                break;                  
            }
        }

        return maxi;
    }
};
