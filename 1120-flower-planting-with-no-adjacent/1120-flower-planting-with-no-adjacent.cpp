class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& color, int currentColor){

        color[node] = currentColor;
        int nextColor = 0;
        if(currentColor == 4) nextColor = 1;
        else nextColor = currentColor +1;

        for(auto it:adj[node]){
            if(color[it] == 0){
                dfs(it,adj,color,nextColor);
            }
            else if(color[it]==color[node]){
                dfs(node,adj,color,nextColor);
            }
        }

    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);

        for(int i=0; i<paths.size(); i++){
            int u = paths[i][0];
            int v = paths[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,0);
        for(int i=1;i<n+1;i++){
            if(color[i] == 0){
                dfs(i,adj, color, 1);
            }
        }
        color.erase(color.begin());
        return color;
    }
};