class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = -1 , l = -1 ;
        for(int i = s.size()-1 ; i>=0 ; i--){
            if(s[i]!=' '&& r==-1){
                r = i;
            }
            if(l==-1 && r!=-1 && s[i]==' '){
                l = i ;
                break;
            }
        }
        int ans = r - l  ;
        return ans ;
    }
};