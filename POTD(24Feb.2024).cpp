class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        set<int>st;
        unordered_map<int,vector<pair<int,int>>>mpp;
        //jhkjhkjhkj
        for(auto&it:meetings)
        {
            mpp[it[0]].push_back({it[1],it[2]});
            mpp[it[1]].push_back({it[0],it[2]});
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({firstPerson,0});

        vector<int>secrettime(n,INT_MAX);
        secrettime[0]=0;
        secrettime[firstPerson]=0;
        while(!q.empty()){
            auto [person,time]=q.front();
            q.pop();
            for(auto [p,t]:mpp[person]){
                if(t>=time && secrettime[p]>t){
                    secrettime[p]=t;
                    q.push({p,t});
                }
            }
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            if(secrettime[i]!=INT_MAX){
                v.push_back(i);
            }
        }
        return v;

    }
};
