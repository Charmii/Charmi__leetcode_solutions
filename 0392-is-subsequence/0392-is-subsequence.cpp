class Solution {
public:
    bool sub(string& s, string& t, int s_len, int t_len){
        cout<<s_len<<" "<<t_len<<" ";
        cout<<s[s_len]<<" "<<t[t_len]<<" ";
        if(t_len == t.length() && s[s_len] != t[t_len]) return false;
        if(s_len == s.length()) return true;

        if( s[s_len] == t[t_len] ) return sub(s,t, s_len+1, t_len+1);
        else return sub(s,t, s_len, t_len+1);
    }
    bool isSubsequence(string s, string t) {
        return sub(s,t,0,0);
    }
};