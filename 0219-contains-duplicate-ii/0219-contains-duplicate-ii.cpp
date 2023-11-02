class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1) return false;
        unordered_set<int> mp;
        for(int i=0; i < nums.size(); i++){
            if(i > k){
                mp.erase(nums[i-k-1]);
            }
            if(mp.find(nums[i]) != mp.end()) return true;
            mp.insert(nums[i]);
        }
        return false;
    }
};