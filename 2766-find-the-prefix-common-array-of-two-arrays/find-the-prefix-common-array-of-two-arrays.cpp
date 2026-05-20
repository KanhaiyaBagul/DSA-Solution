class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
       

        int n = A.size();
        vector<int> freq(n + 1,0);
        vector<int> result(n,0);
        for(int i = 0; i < n; i++){
            freq[A[i]]++;
            freq[B[i]]++;

            int count = 0;

            for(int j = 1; j <= n; j++){
                if(freq[j] > 1){
                    result[i]++;
                }
            }
        }
        return result;

        
    }
};