class Solution {
public:

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int,int>index;
    for(int i=0;i<arr2.size();i++){
        index[arr2[i]]=i;
    }
sort(arr1.begin(),arr1.end(),[&index](int &a,int &b){
    if(index.count(a)&&index.count(b)){
        return index[a]<=index[b];
    }
    else if(index.count(a)){
        return true;
    }
    else if(index.count(b)){
        return false;
    }
    else{
        return a<b;
    }
});
    return arr1;
}
};