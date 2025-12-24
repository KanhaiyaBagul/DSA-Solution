class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> log;
        for(auto& it : logs){
            log[it[0]]++;
            log[it[1]]--;
        }        

        int maxPopulation = INT_MIN;
        int earlyYear = INT_MAX;
        int population = 0;
        
        for(auto& it : log){
            population += it.second;

            if(population > maxPopulation){
                maxPopulation = population;
                earlyYear = it.first;
            }

        }
        return earlyYear;
    }
};