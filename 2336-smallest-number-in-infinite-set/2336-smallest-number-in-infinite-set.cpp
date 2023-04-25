class SmallestInfiniteSet {
public:
    int mn;
    set<int>add;
    SmallestInfiniteSet() {
        mn=1;
    }

    int popSmallest() {
        int ans;
        if(add.empty()){
             ans=mn;
            mn++;
        }
        else{
            ans=*add.begin();
            add.erase(*add.begin());
        }
        return ans;
    }

    void addBack(int num) {
    if(num<mn){
        add.insert(num);
    }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */