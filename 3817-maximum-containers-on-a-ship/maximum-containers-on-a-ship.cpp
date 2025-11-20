class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        // int count = 0;
        // int result = 0;
        // while((maxWeight ) &&  (count < n * n)){
        //     maxWeight -= w;
        //     count++;

        // }
        return min(n * n, maxWeight / w);
    }
};