class Car{
    public: 
    int idx;
    int distSq;

    Car(int idx, int distSq){
        this->idx = idx;
        this -> distSq = distSq;
    }
    //use to Build Min Heap
    //So we “flip” the meaning of <
    bool operator < (const Car &obj) const{
        return this -> distSq > obj.distSq;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<Car> cars;
        vector<vector<int>> result;

        //push the idx and the distSq pait to the cars vector
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int distSq = (x*x) + (y*y);
            cars.push_back(Car(i,distSq));
        }

        //this build a min heap 
        priority_queue<Car> pq(cars.begin(),cars.end());

        //Extract the top element from the heap
        for(int i = 0; i < k; i++){
            int idx = pq.top().idx;
            result.push_back(points[idx]);
            pq.pop();

        }
        return result;

        
    }
};