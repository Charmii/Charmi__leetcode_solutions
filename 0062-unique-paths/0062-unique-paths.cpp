class Solution {
private:
int findMax(int m, int n, vector<vector<int>>& dp){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[m][n] != -1) return dp[m][n];
    int up = findMax(m,n-1, dp);
    int left = findMax(m-1,n, dp);
    return dp[m][n] = up+left;
}
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findMax(m-1,n-1,dp);
    }
};