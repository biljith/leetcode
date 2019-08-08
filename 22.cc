class Solution {
public:
    int total;
    vector<string> res;
    void generateParenthesisInternal(int open, int closed, string s) {
        if (s.length() == 2 * total) res.push_back(s);
        if (open < total)
            generateParenthesisInternal(open + 1, closed, s + "(");
        if (closed < open)
            generateParenthesisInternal(open, closed + 1, s + ")");
    }
    
    vector<string> generateParenthesis(int n) {
        total = n;
        generateParenthesisInternal(0, 0, "");
        return res;
    }
};
