class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = 0;
        int full = numBottles;
        int empty = 0;

        while (full > 0) {
            // Drink all full bottles
            drank += full;
            empty += full;
            full = 0;

            // Try exchanging
            if (empty >= numExchange) {
                empty -= numExchange;   // pay with empty bottles
                full += 1;              // get one new full
                numExchange++;          // exchange cost increases
            } else {
                break; // cannot exchange further
            }
        }
        return drank;
    }
};
