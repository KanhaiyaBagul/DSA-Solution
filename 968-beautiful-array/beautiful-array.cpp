class Solution {
public:
    vector<int> beautifulArray(int n) {

        vector<int> res;
        res.push_back(1);
        

        while (res.size() <n){
            vector<int> temp;
            for (int i = 0;i < res.size(); i++){
            int value = 2*res[i] - 1;
            if(value <= n){
                temp.push_back(value);

            }
        }

        for (int i = 0;i < res.size(); i++){
            int value = 2*res[i];
            if(value <= n){
                temp.push_back(value);

            }
        }

        res = temp;
        
        }
        return res;

        
        
        
    }
};