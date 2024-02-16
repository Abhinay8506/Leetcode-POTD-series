class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

      //Approach-1
      //T.C:O(nlogn)  S.C:O(n)

        map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            
            mpp[arr[i]]++;
              
        }
        vector<int> freq;
        for (auto it : mpp) {
            freq.push_back(it.second);
        }
        
        sort(begin(freq), end(freq));
        
        int count = 0;
        for (int i=0;i<freq.size();i++) {
            if (k >= freq[i]) {
                k -= freq[i];
                count++;
            } else {
                break;
            }
        }
        
        return freq.size() - count;

      //Approach-2
      //T.C:O(N)  S.C:O(N)
      
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }
        
       
        priority_queue<int, vector<int>, greater<int> > frequencies;
        for (auto it : map) {
            frequencies.push(it.second);
        }
        int ele = 0;
        while (!frequencies.empty()) {
           
            ele += frequencies.top();
            if (ele > k) {
                return frequencies.size();
            }
            frequencies.pop();
        }

        return 0;
    }  
};
