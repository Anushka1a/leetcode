class Solution {
public:
    int maxDepth(string s) {
       int res = 0;
        int cur = 0;
        for (char c : s) {
            if (c == '(') {
                cur++;
            } else if (c == ')') {
                cur--;
            }
            res = max(res, cur);
        }
        return res;
    }
};