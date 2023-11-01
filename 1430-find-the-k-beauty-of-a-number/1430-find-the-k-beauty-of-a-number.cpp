class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int count=0;
        const string s = to_string(num);

        for(int i=0; i+k <= s.length(); i++){
            int c = stoi(s.substr(i,k));
            if(c!=0 && num%c == 0) count++;
        }
        return count;
    }
};