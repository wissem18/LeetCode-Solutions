class FoodRatings {
public:
    unordered_map<string,int>rate;
    unordered_map<string,string>c;
    unordered_map<string,set<pair<int,string>>>st;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<ratings.size();i++){
            rate[foods[i]]=ratings[i];
            c[foods[i]]=cuisines[i];
            st[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto it=st[c[food]].find({-rate[food],food});
        st[c[food]].erase(it);
        rate[food]=newRating;
        st[c[food]].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
      return (*st[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */