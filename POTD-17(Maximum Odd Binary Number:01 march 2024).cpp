class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
              if(s[i]=='1')
              {
                  count++;
              }
        }
        string out;

        for(int i=1;i<=count-1;i++){
            
            out.push_back('1');
        }
        for(int i=1;i<=n-count;i++){
             out.push_back('0');
        }
        if(count>0){
            out.push_back('1');
        }
        return out;
    }
};
