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
        return findPath(n-1, m-1, grid, dp);
    }
};


