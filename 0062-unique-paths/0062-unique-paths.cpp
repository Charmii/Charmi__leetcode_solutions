class Solution {
// private:
// int findMax(int m, int n, vector<vector<int>>& dp){
//     if(m==0 && n==0) return 1;
//     if(m<0 || n<0) return 0;
//     if(dp[m][n] != -1) return dp[m][n];
//     int up = findMax(m,n-1, dp);
//     int left = findMax(m-1,n, dp);
//     return dp[m][n] = up+left;
// }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return findMax(m-1,n-1,dp);
        // dp[0][0] = 1;
        vector<int> prev(n,0);
        for(int i=0; i<m; i++){
            vector<int> cur(n);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0){
                    cur[j] = 1;
                }
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = cur[j-1];
                    cur[j] = up + left; 
                }
            }
            prev = cur;
        }
        return prev[n-1];

    }
};