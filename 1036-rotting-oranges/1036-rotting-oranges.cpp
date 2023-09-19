class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int time=0;

        for(int i=0 ;i <n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] =2;
                }
                else vis[i][j] = 0;
            }
        }
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();

            for(int i = 0; i<4; i++){
                int drow= r+delrow[i];
                int dcol = c+delcol[i];
                if(drow>=0 && drow<n && dcol>=0 && dcol<m && !vis[drow][dcol] && grid[drow][dcol] == 1){
                    q.push({{drow,dcol},t+1});
                    vis[drow][dcol] =1;
                    grid[drow][dcol] = 2;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j <m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};