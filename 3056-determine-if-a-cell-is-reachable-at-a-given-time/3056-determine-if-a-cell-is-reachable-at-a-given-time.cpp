class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t != 1;
        }
        int a = abs(sx - fx) + 1;
        int b = abs(sy - fy) + 1;

        int dis = std::min(a, b);
        dis += std::max(a, b) - std::min(a, b);
        dis--;
        return t >= dis;
    }
};