class MyHashMap {
public:
    set<pair<int,int>>st;
    MyHashMap() {

    }

    void put(int key, int value) {
        auto itr=st.lower_bound({key,0});
        if(itr!=st.end()&&itr->first==key)
            st.erase(itr);
        
        st.insert({key,value});
    }

    int get(int key) {
        auto itr=st.lower_bound({key,0});
        if(itr!=st.end()&&itr->first==key)
            return itr->second;
        else
            return -1;

    }

    void remove(int key) {
        auto itr=st.lower_bound({key,0});
        if(itr!=st.end()&&itr->first==key)
            st.erase(itr);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */