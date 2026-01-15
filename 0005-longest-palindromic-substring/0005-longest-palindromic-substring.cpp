class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        int ans = 0, start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (s[i] == s[j]) {
                    if (i == j || i == j + 1 || dp[j + 1][i - 1]) {
                        dp[j][i] = 1;
                        if (i - j + 1 > ans) {
                            ans = i - j + 1;
                            start = j;
                        }
                    }
                }
            }
        }
        return s.substr(start, ans);
    }
};