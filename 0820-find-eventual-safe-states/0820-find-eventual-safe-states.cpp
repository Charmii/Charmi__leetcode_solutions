class Solution {
private: 
    bool dfs(int i, vector<int>&vis, vector<int>& pathvis, vector<vector<int>>& graph, vector<int>& check){
        vis[i] = 1;
        pathvis[i]=1;
        check[i] = 0;

        for(auto it:graph[i]){
            if(!vis[it]){
                if(dfs(it, vis,pathvis,graph, check) == true) {
                    //check[i] = 0;
                    return true;
                }
            }
            else if(pathvis[it]) {
                //check[i] = 0;
                return true;
            }
        }
        check[i] = 1;
        pathvis[i] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,-1);
        vector<int> safe;
        vector<int> check(n);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, vis, pathvis, graph, check);
            }
        }
        for(int i = 0; i<n; i++){
            if(check[i] == 1) safe.push_back(i);
        }
        return safe;
    }
};
