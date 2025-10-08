class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> result(n);

        sort(potions.begin(),potions.end());

        for(int i = 0; i < n; i++){
            long long spell = spells[i];
            
            //apply binary search for finding the first idx which make the conditiion success greater

            int right = m - 1; 
            int left = 0;
            int idx = m;

            while(left <= right){
                int mid = left + (right - left) / 2;
                if(spell*potions[mid] >= success){
                    idx = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }

            }
            result[i] = m - idx;
        }
        return result;
        


    }
};