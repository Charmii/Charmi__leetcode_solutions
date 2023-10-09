class Solution {
private: 
int findPath(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(i == 0 && j == 0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    int up = grid[i][j] + findPath(i-1, j, grid, dp);
    int left = grid[i][j] + findPath(i, j-1, grid,dp);
    dp[i][j] = min(up,left);
    return min(up,left);
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        // return findPath(n-1, m-1, grid, dp);
        dp[0][0] = grid[0][0];
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) dp[0][0] = grid[0][0];
                else {
                    int up = grid[i][j], left = grid[i][j];
                    if(i>0)  up += dp[i-1][j];
                    else up += 1e9;
                    if(j>0)  left += dp[i][j-1];
                    else left+= 1e9;
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};


