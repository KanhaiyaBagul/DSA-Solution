class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> freq;
        

        for(string str : words){
            freq[str]++;
        }

        auto cmp = [](pair<int,string> a , pair<int,string> b){
            if(a.first == b.first){
                return a.second > b.second;
            }

            return a.first < b.first;
        };
    
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(cmp)> pq(cmp);
        for(auto &p : freq){
            pq.push({p.second,p.first});
        }

        vector<string> result;

        for(int i = 1; i <= k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;

        
        
    }
};