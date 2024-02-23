class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)   {
        unordered_map<int,vector<pair<int,int>>>adjacency;//node:[{n1,p1},...]
        for(auto& f:flights){
            adjacency[f[0]].push_back({f[1],f[2]});
        }

        vector<int> dist(n,INT_MAX);//minimum cost
        dist[src]=0;//source to source cost

        queue<pair<int,int>>q;
        q.push({src,0});
        int stops=0;
        while(!q.empty()&&stops<=k){
            int sz=q.size();
            while(sz-- > 0){
                auto [node,distance]=q.front();
                q.pop();
                if(!adjacency.count(node))continue;//terminal

                for(auto& [neighbour,price]:adjacency[node]){
                    if(price+distance>=dist[neighbour])continue;
                    dist[neighbour]=price+distance;
                    q.push({neighbour,dist[neighbour]});

                }
            }
            stops++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];


    }
};
