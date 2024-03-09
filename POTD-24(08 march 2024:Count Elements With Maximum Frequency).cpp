class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int arr[101]={0};
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        int maxfrequency=INT_MIN;
        for(int i=1;i<101;i++)
        {
            maxfrequency=max(maxfrequency,arr[i]);
        }
        int count=0;
        for(int i=1;i<101;i++){
            if(arr[i]==maxfrequency)count++;
        }
        return count*maxfrequency;
    }
};
