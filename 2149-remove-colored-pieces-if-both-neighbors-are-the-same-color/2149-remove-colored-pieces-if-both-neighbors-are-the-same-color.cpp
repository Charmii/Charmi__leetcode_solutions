class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0,bob=0;
        for(int i=1; i<colors.size()-1; i++){
            char prev = colors[i-1];
            char curr = colors[i];
            char next = colors[i+1];
            
            if(prev == 'A' && curr == 'A' && next == 'A') alice++;
            else if(prev == 'B' && curr == 'B' && next == 'B') bob++;
        }
        cout<<alice<<" "<<bob;
        return alice>bob;
    }
};