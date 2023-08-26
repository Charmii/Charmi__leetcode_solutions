class Solution {
public:
    void findCombinations(int index, int k, int target, vector<vector<int>>& ans, vector<int>& ds) {
        cout<<ds.size()<<" "<<index<<" "<<target<<" "<<k<<endl;
        for(int i=0;i<ds.size();i++){
            cout<<ds[i];
        }
        cout<<endl;
        if(index > 10) return;

        if(ds.size() == k || ds.size() == 9){
            cout<<"first id";
            if(target == 0){
                cout<<"pushing";
                ans.push_back(ds);
            }
            return;
        }

            ds.push_back(index);
            findCombinations(index+1, k, target - index, ans, ds);
            ds.pop_back();
            findCombinations(index+1, k, target, ans, ds);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(1, k, n, ans, ds);
        return ans;
    }
};