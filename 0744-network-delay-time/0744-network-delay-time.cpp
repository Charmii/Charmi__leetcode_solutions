class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v,wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int distance = it.first;
            int node = it.second;

            for(auto neighbor:adj[node]){
                int weight = neighbor.second;
                int newNode = neighbor.first;

                if(distance + weight < dist[newNode]){
                    cout<<"updating"<<newNode<<endl;
                    dist[newNode] = distance + weight;
                    pq.push({distance + weight, newNode});
                }
            }
        } 
        int max = -1;
        for(int i=1; i<dist.size();i++){
            // cout<<dist[i]<<" ";
            if(dist[i] == 1e9)return -1;
            max = std::max(dist[i],max);
        }
        return max;
    }
};