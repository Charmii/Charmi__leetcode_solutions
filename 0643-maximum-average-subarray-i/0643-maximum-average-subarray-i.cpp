class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = 0;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(i < k){
                maxSum = sum;
                continue;
            }
            sum -= nums[i-k];

            maxSum = max(sum, maxSum);
        }
        return (double)maxSum / k;
    }
};