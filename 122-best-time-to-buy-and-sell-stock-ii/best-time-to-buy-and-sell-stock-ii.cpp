class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector dp(n+2,vector<int>(3,-1));
        function<int(int  , bool )>calc=[&](int idx , bool have){
            if(idx == n)
                return 0;
            int &ret = dp[idx][have];
            if(~ret)
            return ret;
            ret = 0 ;
            ret = max(ret , calc(idx+1,have));
            if(have)
                ret = max(ret ,prices[idx]+ calc(idx+1,0));
            else
                ret = max(ret , -prices[idx] + calc(idx+1,1));
            return ret;
        };
        return calc(0,0);
    }
};