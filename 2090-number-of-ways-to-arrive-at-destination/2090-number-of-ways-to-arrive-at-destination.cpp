class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[v].push_back({u,wt});
            adj[u].push_back({v,wt});

        }

            priority_queue<pair<long long,int>, vector<pair<long long,int>>,
            greater<pair<long long,int>>> pq;
            vector<long long> dist(n+1,1e15);
            vector<int> ways(n,0);
            dist[0]=0;
            ways[0]=1;
            pq.push({0,0});
            while(!pq.empty()){
                auto it= pq.top();
                pq.pop();
                int node = it.second;
                long long distance = it.first;

                // if (distance > dist[node]) {
                //     continue;
                // }

                for(auto neighbor : adj[node]){
                    int newNode = neighbor.first;
                    int wt = neighbor.second;
                    if(distance + wt < dist[newNode]){
                        dist[newNode] = distance + wt;
                        pq.push({distance + wt, newNode});
                        ways[newNode] = ways[node] ;
                    }
                    else if(distance+wt == dist[newNode]){
                        ways[newNode] = (ways[newNode] + ways[node]) %MOD;
                    }

                }
            }
        return ways[n-1]%MOD;
    }
};