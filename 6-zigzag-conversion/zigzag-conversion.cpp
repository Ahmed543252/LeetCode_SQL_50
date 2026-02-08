class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> me(numRows+2);
        if(numRows==1  )
            return s;
        int idx = 0 , cur = 1;
        for(auto it : s){
            me[idx].push_back(it);
            if(idx==0){
                cur = 1;
            }
            else if(idx == numRows-1){
                cur=-1;
            }
            idx+=cur;
        }
        string res;
        for(int i = 0 ; i <numRows;i++){
          for(auto it : me[i]){
            res+=it;
          }
        }
        return res;
    }
};