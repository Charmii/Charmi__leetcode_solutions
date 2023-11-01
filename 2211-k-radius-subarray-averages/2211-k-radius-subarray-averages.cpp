class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k > nums.size()) {
            vector<int> ans(nums.size(),-1);
            return ans;
        }


        int divisor = (k*2) + 1;
        vector<int> ans;
        //Initial k -1's
        for(int i=0; i<k; i++) ans.push_back(-1);

        //Initial 2*k+1 sum
        long long sum = 0;
        for(int i=0; i<2*k +1; i++) {
            if(2*k+1<=nums.size()){
                sum += nums[i];
            }
        }

        for(int j = 2*k, i=0; j<nums.size(); j++,i++ ){
            ans.push_back(sum/divisor);
            if(j+1<nums.size()) sum += nums[j+1];
            sum -= nums[i];
        }

        // End k -1's
        while(ans.size() < nums.size()) ans.push_back(-1);
        return ans;
    }
};