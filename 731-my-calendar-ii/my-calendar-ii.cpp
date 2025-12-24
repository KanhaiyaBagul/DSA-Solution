class MyCalendarTwo {
public:
    map<int,int> events;
    MyCalendarTwo() {
    }
    

    bool book(int startTime, int endTime) {

        events[startTime]++;//add the start time
        events[endTime]--;//sub the leaving time

        int activeMeeting = 0;
        //it check for the every new interval inserted
        for(auto &interval : events){

            activeMeeting += interval.second;//adding the time of it

            if(activeMeeting >= 3){//if the active Meeting a greater than 3 then
                
                events[startTime]--;//remove the added interval

                if(events[startTime] == 0) events.erase(startTime);//if it become zero then remove that element

                events[endTime]++;
 
                if(events[endTime] == 0) events.erase(endTime);
                return false;
            }

        }
        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */