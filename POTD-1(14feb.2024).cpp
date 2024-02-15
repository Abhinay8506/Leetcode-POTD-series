class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //    Appproach-1
        int n=nums.size();
        vector<int>positive;
        vector<int>negative;
        vector<int>result;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);
                
            }
            else{
                negative.push_back(nums[i]);
            }
        }
        for(int i=0;i<n/2;i++){
            result.push_back(positive[i]);
            result.push_back(negative[i]);
        }
        return result;

        //Approach-2
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIndex = 0, negIndex=1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posIndex] = nums[i];
                posIndex+=2;
            } else {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }

        return ans;
      
    }
};
