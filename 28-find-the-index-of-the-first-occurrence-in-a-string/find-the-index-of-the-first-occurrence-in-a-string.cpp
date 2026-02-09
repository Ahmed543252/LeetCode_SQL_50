class Solution {
public:
    int strStr(string haystack, string needle) {
        int n  = haystack.size(), m = needle.size();
        for(int i = 0 ; i+m-1 < n ; i++){
            bool ok = true;
            for(int j = 0 ; j < m ;j++){
                if(haystack[i+j] != needle[j]){
                    ok= false;
                    break;
                }
            }
            if(ok)
                return i;
        }
        return -1 ;
    }
};