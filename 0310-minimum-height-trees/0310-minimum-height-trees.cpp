class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return{0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0), ans;
        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 1) q.push(i);
        }


        while(q.empty() ==  false){
            int size = q.size();
            ans.clear();

            for(int i = 0;i<size;i++){
                int temp = q.front();
                q.pop();
                ans.push_back(temp);


                for(auto it: adj[temp]){
                    indegree[it]--;
                    if(indegree[it] == 1){cout<<it<<" ", q.push(it);}
                }
            } 
        }
        return ans;
    }
};