class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxAltitude = 0;
        int altitude = 0;

        for(int i = 0; i < n; i++){
            maxAltitude = max(maxAltitude , altitude);

            altitude += gain[i];
        }
        maxAltitude = max(maxAltitude , altitude);
        return maxAltitude; 
    }
};