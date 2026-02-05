class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int  n = gas.size();
        for(int i =0 ; i < n ; i++){
            int j = i , cnt = 0 , total = 0  ;
            while(cnt < n){
                total+=  gas[j % n] - cost[j % n];
                cnt++;
                if(total<0 ){
                    i = j;
                    break;
                }
                j++;
            }
            if(total>=0 && cnt==n)return i;
        }
        return -1 ;
    }
};