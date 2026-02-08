class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        auto can=[&](int mid )->bool{
            vector<string>me;
            for(auto it : strs){
                string mee ="";
                for(int i = 0 ; i <= min<int>(it.size()-1 , mid);i++){
                    mee+=it[i];
                }
                if(mee.size())
                me.push_back(mee);
            }
            bool ok = true;
            for(int i =1 ; i < me.size() ;i++){
                if(me[i]!=me[i-1]){
                    ok = false;
                    break;
                }
            }
            return ok&&(me.size()==strs.size());
        };
        int l = 0 , r = strs[0].size()-1 ,ans =-1 ;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(can(mid)){
                ans = mid ;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        string res ;
        for(int i = 0 ; i <=ans ;i++){
            res+=strs[0][i];
        }
        return res;
    }
};