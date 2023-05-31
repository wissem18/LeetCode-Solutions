class UndergroundSystem {
public:
    unordered_map<string,pair<double,int>>routing;
    unordered_map<int,pair<string,int>>checkin;
            UndergroundSystem() {
            }

    void checkIn(int id, string stationName, int t) {
        checkin[id]={stationName,t};
    }

    void checkOut(int id, string stationName, int t) {
              string key=checkin[id].first+"->"+stationName;
              routing[key].first+=t-checkin[id].second;
              routing[key].second++;
    }

    double getAverageTime(string startStation, string endStation) {
      string key=startStation+"->"+endStation;
      return routing[key].first/routing[key].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */