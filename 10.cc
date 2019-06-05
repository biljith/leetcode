class Solution {
public:
    string s, p;
    bool isMatch(string s, string p) {
        /* if (s.size() == 0) {
            if (p.size() % 2 != 0) return false;
            for (int i = 0; i < p.size(); i += 2) {
                if (p[i] != '.' || p[i + 1] != '*')
                    return false;
            }
            return true;
        }
        if (p.size() == 0) return false;*/
        this->s = s;
        this->p = p;
        return f(0, 0);
    }
    
    bool f(int i, int j) {
        if (i == s.size()) {
            if ((j - p.size()) % 2 != 0) return false;
            for (int z = j; z < p.size(); z += 2) {
                if (p[z + 1] != '*')
                return false;
            }
            return true;
        }
        if (j == p.size()) return false;
        if (s[i] == p[j]) {
            if (j + 1 < p.size() && p[j + 1] == '*')
                return f(i + 1, j + 1) || f(i, j + 2) || f(i + 1, j + 2);
            else return f(i + 1, j + 1);
        }
        else {
            if (p[j] == '*') {
                if (p[j - 1] == s[i] || p[j - 1] == '.') {
                    return f(i + 1, j) || f(i + 1, j + 1);
                } else return false;
            } else if (p[j] == '.') {
                if (j < p.size() - 1 && p[j + 1] == '*')
                    return f(i + 1, j + 1) || f(i, j + 2) || f(i + 1, j + 2);
                else return f(i + 1, j + 1);
                return f(i + 1, j + 1);
            } else if (j < p.size() - 1 && p[j + 1] == '*') {
                return f(i, j + 2);
            } else return false;
        }
        return false;
    }
};
