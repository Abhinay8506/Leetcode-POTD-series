class Solution {
public:
    bool isPowerOfTwo(int n) {
        //Approach-1
        if(n==1)
        {
            return true;
        }
        if(n%2!=0){
            return false;
        }
        else if(n>=2){
           return isPowerOfTwo(n/2);
        }
        return false;



      //Approach-2

      for(int i=0;i<31;i++){
           if(n==pow(2,i))
             return true;
       }
       return false; 
    }
};
