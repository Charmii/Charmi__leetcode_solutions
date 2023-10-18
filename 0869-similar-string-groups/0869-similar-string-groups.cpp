class Solution {
bool areSwapped(const string str1, const string str2) {
    int count = 0; 
    for(int ind =0 ; ind<str1.size(); ind++){
        if(str1[ind] != str2[ind]) count++;
        if(count > 2) return false;
    }
    return count <=2;
}


void dfs(string str, vector<string>& strs, vector<bool>& vis, int index){
    vis[index] = true;

    for(int i=0; i<strs.size(); i++){
        if(vis[i] == false && i!=index){
            if(areSwapped(str, strs[i])){
                dfs(strs[i], strs, vis, i);
            }
        }
        
    }
}
public:
    int numSimilarGroups(vector<string> strs) {
        if(strs.size() == 0) return 0;
        vector<bool> vis(strs.size(),false);
        int count =0;
        for(int i=0; i<vis.size();i++){
            if(vis[i] == false){
                count++;
                dfs(strs[i], strs, vis, i);
            }
        }
        return count;
    }
};