class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        priority_queue< pair<int,pair<int,int>>, 
        vector< pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;

        vector<int> dist(n,1e9);
        dist[src] = 0;
        pq.push({0, {src,0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int stops = it.first;
            int node = it.second.first;
            int distance = it.second.second;

            if(stops>k) continue;

            for(auto newNode: adj[node]){
                int adjNode = newNode.first;
                int adjWt = newNode.second;
                if(distance + adjWt < dist[adjNode] && stops<=k){
                    dist[adjNode] = distance +adjWt;
                    pq.push({stops+1,{adjNode,distance+adjWt}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};