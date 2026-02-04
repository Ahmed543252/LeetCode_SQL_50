class Solution {
public:
    long long NEG = -100000000000000LL;
    vector<vector<long long>> dp;
    vector<vector<bool>> vis;

    long long f(int index, int status, int n, vector<int>& nums) {
        if (index == n) {
            return (status == 3 ? 0 : NEG);
        }

        if (vis[index][status]) 
            return dp[index][status];

        vis[index][status] = true;

        long long take = NEG;
        long long notTake = NEG;

        if (status == 0) {
            notTake = f(index + 1, 0, n, nums);
        }

        if (status == 3) {
            take = nums[index];
        }

        if (index + 1 < n) {
            if (status == 0 && nums[index + 1] > nums[index]) {
                take = max(take, (long long)nums[index] + f(index + 1, 1, n, nums));
            } 
            else if (status == 1) {
                if (nums[index + 1] > nums[index]) {
                    take = max(take, (long long)nums[index] + f(index + 1, 1, n, nums));
                } else if (nums[index + 1] < nums[index]) {
                    take = max(take, (long long)nums[index] + f(index + 1, 2, n, nums));
                }
            } 
            else if (status == 2) {
                if (nums[index + 1] < nums[index]) {
                    take = max(take, (long long)nums[index] + f(index + 1, 2, n, nums));
                } else if (nums[index + 1] > nums[index]) {
                    take = max(take, (long long)nums[index] + f(index + 1, 3, n, nums));
                }
            } 
            else if (status == 3 && nums[index + 1] > nums[index]) {
                take = max(take, (long long)nums[index] + f(index + 1, 3, n, nums));
            }
        }

        return dp[index][status] = max(take, notTake);
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<long long>(4, 0));
        vis.assign(n, vector<bool>(4, false));
        return f(0, 0, n, nums);
    }
};
