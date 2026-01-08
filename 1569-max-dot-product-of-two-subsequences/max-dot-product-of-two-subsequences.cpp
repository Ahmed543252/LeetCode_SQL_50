class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
          int n = nums1.size(), m = nums2.size();
        const int NEG = -1e9;
        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(m + 1, vector<int>(2, NEG))
        );
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j][1] = 0;      // already picked at least one pair
                dp[i][j][0] = NEG;   // picked none → invalid
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int e = 0; e <= 1; e++) {
                    int best = NEG;
                    best = max(best, dp[i + 1][j][e]);
                    best = max(best, dp[i][j + 1][e]);
                    best = max(best,
                        nums1[i] * nums2[j] + dp[i + 1][j + 1][1]
                    );

                    dp[i][j][e] = best;
                }
            }
        }
        return dp[0][0][0];
    }
};