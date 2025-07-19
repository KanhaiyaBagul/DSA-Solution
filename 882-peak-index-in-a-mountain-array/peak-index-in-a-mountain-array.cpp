class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        //In this problem out PEAK INDEX can't be the start and the end value of the arr so we start the starting index at 1 and the ending index at n - 2
        int start = 1;
        int end = n - 2;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]){
                return mid;
            }
            else if(arr[mid - 1] < arr[mid]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }


        }
        return -1;

        
        
    } 
};