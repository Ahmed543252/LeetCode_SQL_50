class Solution {
public:
    int candy(vector<int>& ratings) {
        // just want to move from l to r once 
        // and repeat it from r to l
        int n = ratings.size();
        vector<int>have(n,1);
        for(int i = 1 ; i < n ; i++){
            if(ratings[i]>ratings[i-1]){
                have[i]+=have[i-1];
            }
        }
        for(int i = n-2 ; i >=0 ; i--){
            if(ratings[i]>ratings[i+1] ){
                have[i]= max(have[i] , have[i+1]+1);
            }
        }
        int ans =accumulate(have.begin(),have.end(),0);
        return ans;
    }
};