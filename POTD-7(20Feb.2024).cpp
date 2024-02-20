class Solution {
public:
    int missingNumber(vector<int>& nums) {

      //Approach-1
        /*int ans;
        for(int i=0;i<=nums.size();i++){
            bool f=false;
            for(int j=0;j<nums.size();j++){
              if(nums[j]==i){
                 f=true;
                 break;
              }
            }
            if(f==false){
                ans=i;
                break;
            }
        }
        return ans;
        */

      //Approach-2
        int ans=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i+1){
                ans=i;
                break;
            }
        }
        if(ans==-1){
            return nums.size();
        }
        return ans;

        
    }
};
