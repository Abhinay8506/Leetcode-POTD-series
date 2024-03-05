class Solution {
public:
    int minimumLength(string str) {
    
        int s=0,e=str.size()-1; //s=start,e=end
        while(s<e){
            if(str[s]==str[e]){
                   /*int temp=str[s];
                while(str[s]==str[e] && s<e)s++;
                while(str[e]==temp && s<e)e--;*/
                //failing on edge case as if there will be odd length string then if last one element is remaining then in that case answer will be 0 but it will return 1.
                while(str[s]==str[s+1] && s<e)s++;
                while(str[e]==str[e-1] && s<e)e--;
                s++;
                e--;
               
            }
            else break;
        }
        int ans=e-s+1; //ans=remaining array length
        if(ans<0) return 0;
       
        return ans;
    }
};
