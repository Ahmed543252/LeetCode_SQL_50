class Solution {
public:
    int jump(vector<int>& nums) {
        // state of dp ?? idx 
        int n = nums.size();
        vector<int> dp(n+2,1e9);
        dp[n-1] = 0 ;
        for(int idx =n-2 ; idx>=0 ; idx-- ){
            for(int  i =1 ; i<=nums[idx];i++){
                 if(i+idx<n){
                    dp[idx] = min(dp[idx],1+dp[idx+i]);
                }
                else{
                    break;
                }
            }
        }
        // auto calc=[&](auto && calc , int idx)->int{
        //     if(idx == n-1){
        //         return 0 ;
        //     }
        //     int &ret = dp[idx];
        //     if(~ret)
        //     return ret;
        //     ret = 1e9 ;
        //     for(int i = 1 ; i <= nums[idx] ; i++){
        //         if(i+idx<n){
        //             ret = min(ret ,1+ calc(calc,idx+i));
        //         }
        //         else{
        //             break;
        //         }
        //     }
        //     return ret;
        // };
        return dp[0];
    }
};