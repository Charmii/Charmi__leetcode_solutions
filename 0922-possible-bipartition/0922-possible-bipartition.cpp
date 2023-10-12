class Solution {
private:
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int color){
   
    vis[node] = color;
    cout<<node<< " "<< color<<endl;

    for(auto it:adj[node]){
        if(vis[it] == -1){
            if(!dfs(it, adj, vis, !color)) return false;
        }
        else if(vis[it] == color) return false;
    }
    return true;

}
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1,-1);
        for(int i=0; i<dislikes.size(); i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            cout << "Node " << i << ": ";
            for (auto j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
        for(int i=0; i <n; i++){
            if(vis[i] == -1 && !dfs(i,adj,vis,1)){
                return false;
            }
        }
        return true;
    }
};