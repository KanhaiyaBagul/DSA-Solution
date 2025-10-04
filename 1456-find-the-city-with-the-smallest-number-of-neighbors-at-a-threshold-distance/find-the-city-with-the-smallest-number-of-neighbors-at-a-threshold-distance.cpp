class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // first build the 2d matrix which store all the shortest dist firs
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // first dist from their is 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        //then build the matrix for the initial condtion of each dist as given in the question 
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        //then we apply our alog of Floyd algo
        //then gives the min dist from every node 
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] < INT_MAX && dist[via][j] < INT_MAX) {
                        dist[i][j] =
                            min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int maxIdx = -1;
        int minCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int currCount = 0;
            for (int j = 0; j < n; j++) {
                //here we have to count the how many node are reachable from the current with in the given distThreashold 
                if (dist[i][j] != INT_MAX && dist[i][j] <= distanceThreshold && i != j) {
                    currCount++;
                }
            }

            //for every node get then min nodes with the if they are equal return the max idx
            if(minCount > currCount || (currCount == minCount && i > maxIdx)){
                minCount = currCount;
                maxIdx = i;
            }

            
        }

        return maxIdx;
    }
};