class Solution {
public:
    int countTriples(int n) {

        int result = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j++){
                int a = i;
                int b = j;
                int csquar = a * a + b * b;
                int squc = sqrt(csquar);

                if(squc * squc == csquar && squc <= n){
                    result++;
                }

            }
        }
        return result;
        
    }
};