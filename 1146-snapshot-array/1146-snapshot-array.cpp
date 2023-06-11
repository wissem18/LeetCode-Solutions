class SnapshotArray {
public:
    vector<vector<pair<int,int>>>data;
    int id=0;
    SnapshotArray(int length) {
        data.resize(length);
        for(int i=0;i<length;i++){
            data[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        data[index].push_back({id,val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        pair<int,int>p={snap_id,1e9};
      int x=upper_bound(data[index].begin(),data[index].end(),p)-data[index].begin();
      return data[index][x-1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */