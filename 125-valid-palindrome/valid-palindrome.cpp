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
        string me2 = me;
        reverse(me2.begin(),me2.end());
        cout << me <<endl<<me2;
        if(me != me2)
        return false;
        return true;
    }
};