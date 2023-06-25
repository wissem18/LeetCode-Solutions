class Solution {
public:
     vector<vector<int>> mem;
    int MOD=1e9+7;
    int dp(int currCity, int finish, int remainingFuel,vector<int>& locations) {
        if (remainingFuel < 0) {
            return 0;
        }
        if (mem[currCity][remainingFuel] != -1) {
            return mem[currCity][remainingFuel];
        }

        int ans = currCity == finish ? 1 : 0;
        for (int nextCity = 0; nextCity < locations.size(); nextCity++) {
            if (nextCity != currCity) {
                ans = (ans + dp( nextCity, finish,remainingFuel - abs(locations[currCity] - locations[nextCity]),locations)) %MOD;
            
            }
        }

        return mem[currCity][remainingFuel] = ans;
    }
        int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        mem.assign(n, vector<int>(fuel + 1, -1));
        return dp(start, finish, fuel,locations);
    }
};