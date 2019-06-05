class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        if (s.length() == 1) return s;
        bool dp[1001][1001];
        for (int i = 0; i < s.length(); ++i) {
            dp[i][0] = true;
            dp[i][1] = true;
        }
        
        int maxLen = 1;
        int start = 0;
        for (int len = 2; len <= s.length(); ++len) {
            for (int i = 0; i <= s.length() - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][len - 2]) {
                    dp[i][len] = true;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
                else dp[i][len] = false;
            }
        }
        return s.substr(start, maxLen);
    }
};
