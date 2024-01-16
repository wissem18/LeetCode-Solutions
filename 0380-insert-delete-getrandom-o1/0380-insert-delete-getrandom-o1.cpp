class RandomizedSet {
public:
    vector<int>a;
    unordered_map<int,int>ind;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(ind.find(val)!=ind.end())return false;
        a.push_back(val);
        ind[val]=a.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(ind.find(val)==ind.end())return false;
        ind[a[a.size()-1]]=ind[val];
        a[ind[val]]=a[a.size()-1];
        a.pop_back();
        ind.erase(val);
        return true;
    }
    
    int getRandom() {
        return a[rand()%a.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */