class Solution {
public:
    double angleClock(int hour, int minutes) {
        //for the hour hand it move 30 degree per hour  , and the hour hand move 0.5 perminute
        double hourHand = (hour * 30) + (minutes * 0.5);

        //for minuter hand it move 6 degree per minute
        double minuteHand = minutes * 6;

        double diff = abs(hourHand - minuteHand);

        return min(diff, 360 - diff); 
    }
};