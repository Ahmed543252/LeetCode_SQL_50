class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int n = nums.size();
        vector<int>tmp(nums.begin()+(n-k),nums.end());
        for(int i = 0 ; i < n-k ;i++){
            tmp.push_back(nums[i]);
        }
        nums=tmp;
        return ;
    }
};