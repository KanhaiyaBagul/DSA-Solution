class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> free;
        unordered_map<char,int> freq;
        priority_queue<pair<int,char>> pq;
        for(char ch : tasks){
            freq[ch]++;
            free[ch] = 1;
        }


        for(auto &p : freq){
            pq.push({p.second,p.first});
        }

        int seat = 1;

        while(!pq.empty()){
            vector<pair<int,char>> pulled;
            while(!pq.empty()){
                auto [freq, child] = pq.top();
                pq.pop();

                if(free[child] <= seat){
                    free[child] = seat + n + 1;
                    if(freq > 1){
                        pq.push({freq-1,child});
                    }
                    break;
                }else{
                    pulled.push_back({freq,child});
                }
            }

            for(int i = 0; i < pulled.size(); i++){
                pq.push(pulled[i]);
            }

            seat++;

        }
        return seat - 1;


        
    }
};