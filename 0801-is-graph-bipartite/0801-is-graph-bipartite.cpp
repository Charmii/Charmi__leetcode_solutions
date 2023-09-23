class Solution {
private:
    bool dfs(int i, vector<int>& color, vector<vector<int>>& graph,int clr){
        color[i] = clr;
        for(auto next:graph[i]){
            if(color[next] == -1){
                if(!dfs(next,color,graph,!clr)) return false;
            }
            if(color[i] == color[next]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i] == -1 && !dfs(i,color,graph,1)){
                return false;
            }
        }
        return true;
    }
};