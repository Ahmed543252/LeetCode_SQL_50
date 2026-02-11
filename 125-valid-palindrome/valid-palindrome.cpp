class Solution {
public:
    bool isPalindrome(string s) {
        string me;
        for(auto it : s){
            if(isalpha(it) ){
                me+=tolower(it);
            }
            else if(isdigit(it)){
                me+=it;
            }
        }
      int n = me.size();
      for(int i = 0 ;i < n/2 ; i++){
        if(me[i]!=me[n-i-1])
        return false;
      }
      return true;
    }
};