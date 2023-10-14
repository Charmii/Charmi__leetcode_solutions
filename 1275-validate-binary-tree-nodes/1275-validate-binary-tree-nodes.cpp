class Solution {
private: 
bool dfs(int node, vector<vector<int>>& adj, vector<int>&vis){
    cout<<node<<endl;
    if(vis[node] == 1) return false;
    vis[node] = 1;
    for(auto it:adj[node]){
        if(it == -1) continue;
        if(dfs(it,adj,vis) == false) return false;
    }
    return true;
}
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n,0);
        vector<int> outdegree(n,0);
        int root=-1, countroots=0;

        for (int i = 0; i < n; i++) {
            adj[i].push_back(leftChild[i]);
            adj[i].push_back(rightChild[i]);
            if(leftChild[i] != -1){
                indegree[leftChild[i]]++;
                outdegree[i]++;
                if(indegree[i] > 1) {
                    // cout<<"returnong indegree";
                    return false;
                    }
            }
            if(rightChild[i] != -1){
                indegree[rightChild[i]]++;
                outdegree[i]++;
                if(outdegree[i] > 2) {
                    // cout<<"returnong outdegree";
                    return false;}
            }
        }
        
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                root = i;
                countroots++;
            }
        }
        if(root == -1) return false;
        if(countroots > 1) {
            cout<<countroots;
            // cout<<"returning counts";
            return false;}

        for(int i=0; i<n;i++){
            for(auto j:adj[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }

        vector<int> vis(n,0);
        cout<<"Root"<<root<<endl;
        bool ans = dfs(root, adj, vis);
        for(int i=0; i<n; i++){
            if(vis[i] != 1) return false;
        }
        return ans;
    }
};