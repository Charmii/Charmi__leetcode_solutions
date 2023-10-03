class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++; 
        }
        int total_count = 0;
        for(auto num:mp){
            total_count += (num.second * (num.second-1)) /2;
        }
        return total_count;
    }
};