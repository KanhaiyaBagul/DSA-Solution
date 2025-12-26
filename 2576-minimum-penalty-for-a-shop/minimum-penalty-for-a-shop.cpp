class Solution {
public:
    int bestClosingTime(string customers) {

        int minResult = INT_MAX;
        int earlyHour = INT_MAX;

        int totalY = 0;
        for(char ch : customers) if(ch == 'N') totalY++;

        int N = 0;
        int Y = 0;

        for (int i = 0; i <= customers.size(); i++) {

            int penelty = N + (totalY - Y);

            if(customers[i] == 'N') N++;
            else Y++;






            if (minResult > penelty) {
                minResult = penelty;
                earlyHour = i;
            }
        }
        return earlyHour;
    }
    
};