// basic structure for info about each row , the count of 1 , and the index
class Row{
    public:
    int count;
    int idx;

    Row(int count, int idx){
        this -> count = count;
        this -> idx  = idx;
    }

    //comparizon operator
    bool operator <(const Row &obj ) const{
        if(this -> count == obj.count){
            return this -> idx > obj.idx;
        }
        return this -> count > obj.count;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        vector<Row> rows;

        //this calculatte the count of 1 and it's index
        for(int i = 0; i < mat.size(); i++){
            int count = 0;
            for(int j = 0; j < mat[0].size() && mat[i][j] == 1; j++){
                count ++;
            }
            rows.push_back(Row(count, i));//push to the rows vector
        }

        priority_queue<Row> pq(rows.begin(),rows.end()); //make a min heap of it

        //store the top weakest row idx
        for(int i = 0; i < k ; i++){
            int idx  = pq.top().idx;
            result.push_back(idx);
            pq.pop();
        }
        return result;
    }
};