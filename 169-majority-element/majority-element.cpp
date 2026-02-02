class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>st;
        for(auto it : nums)
            st[it]++;
        for(auto it : st){
            if(it.second>(nums.size()/2)){
                return it.first;
            }
        }
        return 0;
    }
};