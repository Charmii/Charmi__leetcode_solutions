class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        int threshold = nums.size()/3;
        for( auto current: mp){
            if(current.second > threshold){
                ans.push_back(current.first);
            }
        }
        return ans;
    }
};