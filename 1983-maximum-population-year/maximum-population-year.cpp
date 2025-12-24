class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> log;
        //first make a map , if any born increment 1 , any die decrement 1
        for(auto& it : logs){
            log[it[0]]++;
            log[it[1]]--;
        }        

        int maxPopulation = INT_MIN;//for the max Population
        int earlyYear = INT_MAX;//for the early year
        int population = 0;//for the curr Population
        
        for(auto& it : log){
            population += it.second;//add the if it is born or dead

            if(population > maxPopulation){//if we found the bigger population than maxPopulation , update the maxPopulation and also update the earlyYear
                maxPopulation = population;
                earlyYear = it.first;
            }

        }
        return earlyYear;
    }
};