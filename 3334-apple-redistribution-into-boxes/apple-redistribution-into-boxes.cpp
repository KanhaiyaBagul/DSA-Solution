class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(),apple.end(),0);

        sort(capacity.begin(),capacity.end(),greater<int> ());

        int currSum = 0;
        int i = 0;

        for(;i < capacity.size(); i ++){
            currSum += capacity[i];

            if(currSum >= totalApples) break;
        }
        return i + 1;
        
        
    }
};