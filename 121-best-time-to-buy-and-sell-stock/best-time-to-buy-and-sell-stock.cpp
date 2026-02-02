class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(is_sorted(prices.rbegin(),prices.rend()))
            return 0;
        int ans =0  , n = prices.size();
        vector<int>mx(n+2);
        for(int i = n-1 ; i >=0 ;i--)
            mx[i]=max(mx[i+1],prices[i]);
        for(int i = 0 ; i+1 <n ;i++){
            ans = max(ans , mx[i+1]-prices[i]);
        }
        return ans ;
    }
};