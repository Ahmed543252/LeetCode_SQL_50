class Solution {
public:
    int jump(vector<int>& nums) {
        // state of dp ?? idx 
        int n = nums.size();
        vector dp(n+2,-1);
        auto calc=[&](auto && calc , int idx)->int{
            if(idx == n-1){
                return 0 ;
            }
            int &ret = dp[idx];
            if(~ret)
            return ret;
            ret = 1e9 ;
            for(int i = 1 ; i <= nums[idx] ; i++){
                if(i+idx<n){
                    ret = min(ret ,1+ calc(calc,idx+i));
                }
                else{
                    break;
                }
            }
            return ret;
        };
        return calc(calc,0);
    }
};