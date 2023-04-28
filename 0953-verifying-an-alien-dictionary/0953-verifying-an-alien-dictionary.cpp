class Solution{
public:
bool isAlienSorted(vector<string>& words, string order) {
    vector<string>a=words;
sort(a.begin(),a.end(),[&order](const string &a,const string &b){
    for (int i = 0; i < min(a.size(),b.size()); ++i) {
        if(order.find(a[i])<order.find(b[i]))
            return true;
        else if(order.find(a[i])>order.find(b[i]))
            return false;
    }
    if(a.size()<=b.size())
        return true;
    return false;
});
return(words==a);
}
};