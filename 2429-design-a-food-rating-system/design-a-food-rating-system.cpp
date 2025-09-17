class FoodRatings {
private:
    // food -> {cuisine, rating}
    unordered_map<string, pair<string,int>> foodInfo;
    
    // cuisine -> set of foods sorted by { -rating, food }
    unordered_map<string, set<pair<int,string>>> cuisineSets;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string f = foods[i];
            string c = cuisines[i];
            int r = ratings[i];
            
            foodInfo[f] = {c, r};
            cuisineSets[c].insert({-r, f}); // store -rating for max-order
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        
        // Remove old record
        cuisineSets[cuisine].erase({-oldRating, food});
        
        // Insert new record
        cuisineSets[cuisine].insert({-newRating, food});
        
        // Update map
        foodInfo[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        // The first element in the set is the highest rated
        return cuisineSets[cuisine].begin()->second;
    }
};
