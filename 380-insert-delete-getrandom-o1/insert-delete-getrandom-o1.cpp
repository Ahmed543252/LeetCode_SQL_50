class RandomizedSet {
    private:
    vector<int>v;
    unordered_map<int,int>mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)==0){
            mp[val] = v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
         if(mp.count(val)==0){
            return false;
        }
       int pos = mp[val];
       v[pos] = v.back();
       mp[v.back()] = pos;
       v.pop_back();
       mp.erase(mp.find(val));
        return true;
    }
    
    int getRandom() {
          return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */