class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string me  ;
        bool ok = false;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]!=' '){
              ok = true;  
            }
            if(s[i]==' '&& ok){
                v.push_back(me);
                me="";
                ok= false;
            }
            if(ok){
                me+=s[i];
            }
            
        }
        if(me.size()){
            v.push_back(me);
        }
        string ans ;
        for(int i = v.size()-1 ; i>=0 ;i--){
            ans = ans + v[i] +' ';
        }
        ans.pop_back();
        return ans ;
    }
};