class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;

        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < fruits.size(); right++){
            m[fruits[right]]++;

            while(m.size() > 2){
                m[fruits[left]]--;

                if(m[fruits[left]] == 0){
                    m.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen , right - left + 1);
        }
        return maxLen;
        
    }
};