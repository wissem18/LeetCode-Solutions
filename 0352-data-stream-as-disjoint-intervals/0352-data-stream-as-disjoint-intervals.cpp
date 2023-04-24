class SummaryRanges {
public:
    multiset<int>list;
    SummaryRanges() {
        list={};
    }

    void addNum(int value) {
        list.insert(value);
    }

    vector<vector<int>> getIntervals() {
      vector<vector<int>>result;
       if(list.empty())
           return result;
       int s=*list.begin();
       int e=*list.begin();
        for (auto x:list) {
            if(x-e<=1){
                e=x;
            }
            else{
                vector<int>a={s,e};
                result.push_back(a);
                s=e=x;
            }
        }
        vector<int>a={s,e};
                result.push_back(a);
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */