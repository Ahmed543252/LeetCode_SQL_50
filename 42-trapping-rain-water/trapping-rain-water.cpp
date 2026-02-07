class Solution {
public:
    int trap(vector<int>& height) {
        // i want to know first block greater than me before & after me
        int ans = 0 , n = height.size();
        vector<int>pre(n),suff(n);
        pre[0] = height[0];
        suff[n-1] = height[n-1];
        for(int i =1 ; i < n ;i++){
            pre[i] = max(pre[i-1] , height[i]);
        }
        for(int i = n -2 ; i>=0 ;i--){
            suff[i] = max(suff[i+1] , height[i]);
        }
        for(int i = 1 ; i< n-1 ;i++){
            int a= pre[i-1] , b = suff[i+1];
            int me = min(a,b);
            // cout << me <<" "<<height[i]<<endl;
            ans +=max(0,me-height[i]);
        }
        return ans ;
    }
};