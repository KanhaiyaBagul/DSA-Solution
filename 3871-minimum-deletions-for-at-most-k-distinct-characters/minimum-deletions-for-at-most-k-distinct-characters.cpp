class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        
        priority_queue<int , vector<int> , greater<int>>pq;
        for(auto& pair : freq){
            pq.push(pair.second);
        }

        int result = 0;
        if(pq.size() > k){
            while(pq.size() != k){
            result+=pq.top();
            pq.pop();
            
        }
        }
        return result;
    }
};