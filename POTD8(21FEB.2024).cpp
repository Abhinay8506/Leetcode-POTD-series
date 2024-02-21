class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        /*int ans=0;
        for(int i=left+1;i<=right;i++){
              ans=an;s&i;
        }
        return ans;*/
      

        while(right>left){
            right=right&right-1;
        }
        return right;


    }
}; 
