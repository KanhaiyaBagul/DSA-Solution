class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> result(n,0);
        for(int i = n - 1; i >= 0;i--){
            int curr = temperatures[i];

            while(!s.empty() && curr >= temperatures[s.top()]){
                s.pop();
            }

            if(s.empty()){
                result[i] = 0;
            }else{
                result[i] = s.top() - i;
            }

            s.push(i);
        }
        return result;
        
    }
};