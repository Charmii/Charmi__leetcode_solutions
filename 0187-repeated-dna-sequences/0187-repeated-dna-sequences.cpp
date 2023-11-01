class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        int k=10;
        string sub = s.substr(0,10);
        mp[sub] = 1;
        cout<<sub<<endl;
        for(int i=10; i < s.length(); i++){
            sub += s[i];
            sub = sub.substr(1);
            mp[sub]++;
        }
        vector<string> ans;
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second >1) ans.push_back(it.first);
        }
        return ans;
        
    }
};