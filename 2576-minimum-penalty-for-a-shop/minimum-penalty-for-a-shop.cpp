class Solution {
public:
    int bestClosingTime(string customers) {

        int minResult = INT_MAX;
        int earlyHour = INT_MAX;

        int totalY = 0;
        //find totalNumber of "N" in the string
        for(char ch : customers) if(ch == 'N') totalY++;

        int N = 0;//count the "N"
        int Y = 0;//count the "Y"

        for (int i = 0; i <= customers.size(); i++) {

            int penelty = N + (totalY - Y);//calculate the panelty , this is just the calculation of the "Y" and "N" for starting the the number of N = 0 caculate like 
            //before the i th calculate how many number of "N" and after that aftert i th calculate the Number of "Y" this solve the problem

            //this condition are use to before the i th calculate how many "N" and "Y" appear
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