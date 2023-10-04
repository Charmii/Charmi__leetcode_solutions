class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& rooms){
        vis[node] = 1;
        cout<<node<<endl;
        for(auto adj:rooms[node]){
            if(!vis[adj]) dfs(adj,vis,rooms);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int nodes = rooms.size();
        vector<int> vis(nodes,0);
        // for(int i=0; i<nodes; i++){
        //     if(!vis[i]){
                dfs(0, vis, rooms);
        //     }
        // }
        for(int i=0; i<nodes; i++){
            cout<<i<<" "<<vis[i]<<endl;
            if(vis[i] == 0) return false;
        }
        return true;
    }
};