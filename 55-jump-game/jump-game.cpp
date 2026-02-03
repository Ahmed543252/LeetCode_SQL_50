class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return true;
        for (int i = 0; i < n; i++) {
            bool ok = false;
            if (nums[i] == 0) {
                for (int j = 0; j < i; j++) {
                    int dis = i - j;
                    if (nums[j] > dis ||(nums[j] >= dis && i==n-1) ) {
                        ok = true;
                        break;
                    }
                }
                if (ok == false)
                    return false;
            }
        }
        return true;
    }
};