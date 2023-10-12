class Solution {
private: 
void dfs(int node, vector<vector<int>>& ans, vector<int>& path, vector<vector<int>>& graph, int n){
    //Enter node into path
    path.push_back(node);
    cout<<endl;

    if(node == n-1){
        ans.push_back(path);
    }

    //dfs
    for(auto it:graph[node]){
        dfs(it,ans, path, graph, n);
    }

    //Pop node from path
    path.pop_back();
}
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, ans, path, graph, n);
        return ans;
    }
};