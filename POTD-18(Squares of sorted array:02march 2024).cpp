class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(nums.size());
        int i=0;
        int j=n-1;
        for(int p=n-1;p>=0;p--){
            int val;
            if(abs(nums[i])<abs(nums[j])){
                val=nums[j];
                j--;

            }
            else{
                val=nums[i];
                i++;
            }
            ans[p]=val*val;
        }
        return ans;



    }
};
