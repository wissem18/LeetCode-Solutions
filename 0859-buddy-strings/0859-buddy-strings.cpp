class Solution {
public:
 bool buddyStrings(string s, string goal) {
    if(s.size()!=goal.size())
        return false;
    char c1,c2,c3,c4;
    int nb=0;
    vector<int>pos(26,0);
    for (int i = 0; i < s.size(); ++i) {
        pos[s[i]-'a']++;
        if(s[i]!=goal[i]){
            nb++;
            if(nb==1){
                c1=s[i];
                c2=goal[i];
            }
            else if(nb==2){
                c3=s[i];
                c4=goal[i];
            }
            else
                break;
        }
    }
    return ((nb==2&&c1==c4&&c2==c3)||(s==goal&& *max_element(pos.begin(),pos.end())>1));
}
};