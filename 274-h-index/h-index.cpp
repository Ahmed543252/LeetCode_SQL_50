class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(),citations.rend());
        int ans = 0,n =citations.size();
        for(int i = 0 ; i < n;i++){
            if(citations[i] > ans)
                ++ans;
        }
        return ans;
    }
};