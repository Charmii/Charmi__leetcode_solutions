class Solution {
private: 
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        cout<<i<<" "<<j<<" "<<endl;
        if(j < 0 || j >= matrix[0].size()) return 1e8;
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + solve(i-1, j, matrix, dp);
        int left_up = matrix[i][j] + solve(i-1, j-1, matrix, dp);
        int right_up = matrix[i][j] + solve(i-1, j+1, matrix, dp);

        return dp[i][j] = min(up, min(left_up, right_up));
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,0));

        for(int j = 0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }
         
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int left_up = 1e8, right_up = 1e8;
                if(j-1 >= 0){
                    left_up = matrix[i][j] + dp[i-1][j-1];
                }
                if(j+1 < m){
                    right_up = matrix[i][j] + dp[i-1][ j+1];
                }
                dp[i][j] = min(up, min(left_up, right_up));
            }
        }
        for(int j = 0; j < m; j++) {
             mini = min(mini, dp[n-1][j]);
         }
        return mini;
    }
};
