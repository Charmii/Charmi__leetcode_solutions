class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_left = INT_MIN, max_right = INT_MIN;
        for(int i=0;i<left.size(); i++){
            max_left = max(max_left, left[i]);
        }
        for(int i=0;i<right.size(); i++){
            max_right = max(max_right, n - right[i]);
        }
        return max(max_left, max_right);
    }
};