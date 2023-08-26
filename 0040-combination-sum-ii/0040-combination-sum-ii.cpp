class Solution {
public:
    void recursion(int index, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < candidates.size();i++){
            if(i> index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            //if(candidates[index] < target){
            ds.push_back(candidates[i]);
            recursion(i+1, candidates, target - candidates[i], ans, ds);
            ds.pop_back();
            //}
        }
        
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        recursion(0, candidates, target, ans, ds);
        return ans;
    }
};

void findCombi(int index,int target,vector<int>& arr,vector<vector<int>> &ans,vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = index;i<arr.size();i++){
            if(i> index && arr[i] == arr[i-1]){
                continue;
            }

            if(arr[i] > target){
                break;
            }
            ds.push_back(arr[i]);
            findCombi(i + 1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombi(0,target,candidates,ans,ds);
        return ans;
       
    }