class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    list<int> a;
    int c;
    void moveToFirst(int key){
        a.erase(mp[key].first);
        a.push_front(key);
        mp[key].first=a.begin();
    }
    LRUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;   
        moveToFirst(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            moveToFirst(key);
        }
        else{
            a.push_front(key);
            mp[key]={a.begin(), value};
            c--;
        }
        
        if(c<0){
            mp.erase(a.back());
            a.pop_back();
            c++;
        }        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */