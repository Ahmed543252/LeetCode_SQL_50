class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector(2, vector<int>(k + 1, -1)));

        auto calc = [&](auto&& calc, int idx, bool have, int cnt) -> int {
            if (cnt > k)
                return -1000000000;

            if (idx == n)
                return have ? -1000000000 : 0;

            int& ret = dp[idx][have][cnt];
            if (ret != -1)
                return ret;

            ret = calc(calc, idx + 1, have, cnt);

            if (have)
                ret = max(ret, prices[idx] + calc(calc, idx + 1, 0, cnt + 1));
            else
                ret = max(ret, -prices[idx] + calc(calc, idx + 1, 1, cnt));

            return ret;
        };

        return calc(calc, 0, 0, 0);
    }
};
