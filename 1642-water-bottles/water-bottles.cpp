class Solution {
public:
    //randomly solve zala
    int numWaterBottles(int numBottles, int numExchange) {
        //the number of bottel we drink at the first
        int result = numBottles;

        //after drinking it become empty
        int emptyBottles = numBottles;
        
        //we run the loop untill no of empty bottle are less than the numExchange , we can't exchange no other bottle form it and stop the loop
        while (emptyBottles / numExchange != 0) {
            //we add the number of bottle which can we drink
            result += emptyBottles / numExchange;
            //after drinking the bottle it become empty add to the empty bottle , and if any remainig bottle are their also add them to the emptybottle
            emptyBottles = emptyBottles / numExchange + emptyBottles % numExchange;
        }
        return result;
    }
};