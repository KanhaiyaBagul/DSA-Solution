class Solution {
public:

    bool hasZero(int x) {
    while (x > 0) {
        if (x % 10 == 0) return true; // found zero
        x /= 10;
    }
    return false;
}
    vector<int> getNoZeroIntegers(int n) {

        for(int i = 1; i <= n; i++){
            int num1 = i;
            int num2 = n - i;
            if(!hasZero(num1) && !hasZero(num2)){
                return {num1, num2};
                break;
            }

        }
        return {};   
    }
};