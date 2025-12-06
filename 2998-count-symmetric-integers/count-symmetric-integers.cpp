class Solution {
public:
    bool isSymmetry(int x){
        string str = to_string(x);
        int len = str.size();

        if(len % 2) return false;

        int sum1 = 0;

        for(int i = 0; i < len / 2; i++){
            sum1 += str[i] - '0';
        }

        int sum2 = 0;
        for(int i = len / 2; i < len; i++){
            sum2+= str[i] - '0';

        }
        return sum1 == sum2;

    }
    int countSymmetricIntegers(int low, int high) {
        int result = 0;

        for(int i = low; i <= high; i++){
            if(isSymmetry(i)){
                result ++;
            }

        }
        return result;
        
    }
};