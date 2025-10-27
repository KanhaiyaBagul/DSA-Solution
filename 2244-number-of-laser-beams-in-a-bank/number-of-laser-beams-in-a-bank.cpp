class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        int n = bank.size();
        int m = bank[0].size();
        int laser = 0;

        vector<int> store(n,0);//store the data, in which row how many devices are their

        for(int i = 0; i < n; i++){//this use to go through all the places
            int security = 0;
            for(int j = 0; j < m; j++){
                
                if(bank[i][j] == '1'){
                    security++;
                }
                store[i] = security;
            }
        }

        vector<int> arr;//this arr store the non zero rows which has the devices
        for(int i = 0; i < store.size(); i++){
            if(store[i] != 0){
                arr.push_back(store[i]);
            }
        }

        int result = 0;//this simplly calculat the laser beem using the simple formula
        for(int i = 1; i < arr.size(); i++){
            result += arr[i-1] * arr[i];
        }
        return result;
        
    }
};