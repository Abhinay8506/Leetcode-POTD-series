//Find Polygon With the Largest Perimeter

//Approach-1:Prefix sum and sorting
class Solution {
public:
    long long largestPerimeter(vector<int>& nums){

        //Approach-1:Sorting and Prefix sum
        sort(nums.begin(),nums.end());//time :nlogn
        vector<long long>prefixsum(nums.size());//space:n
        prefixsum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        int side=nums.size();
        for(int i=nums.size()-1;i>=2;i--){
            if(nums[i]>=(prefixsum[i]-nums[i]))
            {
                side--;
            }
            else{
                return prefixsum[i];
            }
        }
        return -1;

        

    }
};
