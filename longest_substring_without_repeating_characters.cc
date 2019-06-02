class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int res = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            if (m.find(s[j]) == m.end()) {
                m[s[j]] = 1;
            } else {
                m[s[j]]++;
            }
            while (m[s[j]] > 1) {
                m[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
