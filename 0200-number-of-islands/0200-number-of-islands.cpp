class Solution {
private:
    void bfs(int row, int col, vector<vector<char>> grid, vector<vector<int>>& vis){
        vector<int> drow= {1,0,0,-1};
        vector<int> dcol= {0,1,-1,0};
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int qrow = q.front().first;
            int qcol = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int delrow = qrow + drow[i];
                int delcol = qcol + dcol[i];

                if(delrow >= 0 && delrow<n && delcol >= 0 && delcol < m && !vis[delrow][delcol] && grid[delrow][delcol] == '1'){
                    cout<<delrow<<delcol<< " ";
                    q.push({delrow,delcol});
                    vis[delrow][delcol] = 1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cout<<i<<j<<endl;
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};