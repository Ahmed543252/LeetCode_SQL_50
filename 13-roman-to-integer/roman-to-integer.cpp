class Solution {
public:
    int romanToInt(string s) {
        int ans = 0 ;
        map<char, pair<int,int>>mp;
        mp['I'] = {1,1};
        mp['V'] = {5,2};
        mp['X'] = {10,3};
        mp['L'] = {50,4};
        mp['C'] = {100,5};
        mp['D'] = {500,6};
        mp['M'] = {1000,7};
        for(int i = 0 ; i <s.size(); i++){
            if(i+1 < s.size()&&mp[s[i]].second < mp[s[i+1]].second){
                ans-=mp[s[i]].first;
            }
            else{
                ans+=mp[s[i]].first;
            }
        }
        return ans ;
    }
};