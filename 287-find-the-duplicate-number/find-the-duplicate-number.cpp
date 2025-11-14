class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // we have to use slow - fast pointer in here
        int slow = 0;
        int fast = 0;

        while (1) {

            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            //we find he loop
            if (slow == fast) {
                slow = 0;
                //this find the repeated element
                while (slow != fast) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }
        }
        return -1;
    }
};