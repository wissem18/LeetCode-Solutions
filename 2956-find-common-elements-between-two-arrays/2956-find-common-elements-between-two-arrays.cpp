class Solution {
public:

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
vector<int>occ1(101,0);
    for (int i = 0; i < nums1.size(); ++i) {
        occ1[nums1[i]]++;
    }
    vector<int>occ2(101,0);
    for (int i = 0; i < nums2.size(); ++i) {
        occ2[nums2[i]]++;
    }
    int x=0;
    for (int i = 0; i < nums1.size(); ++i) {
        if(occ2[nums1[i]])
            x++;
    }
    int y=0;
    for (int i = 0; i < nums2.size(); ++i) {
        if(occ1[nums2[i]])
            y++;
    }
    return{x,y};
}
};