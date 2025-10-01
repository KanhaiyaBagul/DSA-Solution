class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        int emptyBottles = numBottles;
        while (emptyBottles / numExchange != 0) {
            result += emptyBottles / numExchange;
            emptyBottles = emptyBottles / numExchange + emptyBottles % numExchange;
        }
        return result;
    }
};