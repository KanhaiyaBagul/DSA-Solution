class MyCalendarTwo {
public:
    map<int,int> events;
    MyCalendarTwo() {
    }
    

    bool book(int startTime, int endTime) {

        events[startTime]++;
        events[endTime]--;

        int activeMeeting = 0;

        for(auto &interval : events){

            activeMeeting += interval.second;

            if(activeMeeting >= 3){
                events[startTime]--;

                if(events[startTime] == 0) events.erase(startTime);

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