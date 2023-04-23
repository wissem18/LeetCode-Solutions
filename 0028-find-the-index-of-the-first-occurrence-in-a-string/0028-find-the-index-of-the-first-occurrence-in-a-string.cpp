class Solution {
public:
    int strStr(string haystack, string needle) {
    if(needle.size()>haystack.size())
        return -1;
    deque<int>x1;
    deque<int>x2;
    for(auto c:needle){
        x1.push_back(c-'a');
    }
    for(int i=0;i<needle.size();i++){
        x2.push_back(haystack[i]-'a');
    }
    if(x1==x2)
        return 0;
    for(int i=needle.size();i<haystack.size();i++){
        x2.push_back(haystack[i]-'a');
        x2.pop_front();
        if(x1==x2){
            return i-needle.size()+1;
        }
    }
    return -1;
}
};