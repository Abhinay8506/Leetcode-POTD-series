class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<int,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        string res="";
        for(int i=0;i<order.size();i++){
           if(mpp.find(order[i])!=mpp.end()){
               res.append(mpp[order[i]],order[i]);
               mpp.erase(order[i]);
           }
        }
        for(auto &it:mpp){
             res.append(it.second,it.first);
        }
        return res;

    }
};
