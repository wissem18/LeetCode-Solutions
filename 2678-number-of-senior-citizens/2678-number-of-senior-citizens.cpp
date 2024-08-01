class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(int i=0;i<details.size();i++){
            string age="";
            age+=details[i][11];
            age+=details[i][12];
            if(stoi(age)>60)
                ans++;
        }
        return ans;
    }
};