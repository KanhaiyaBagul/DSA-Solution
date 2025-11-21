class Solution {
public:
    //this simple intution to solve this problem is first find the left most and the right most occurance of the element then count how many unique element is present in that it gives the number of the palindrom which can be form using those elemnets 
    int countPalindromicSubsequence(string s) {
        vector<int> right(26,-1);//this soter the rightmost index of the element form a to z
        vector<int> left(26,-1);//this store the left most index of a element

        //here we find the index
        for(int i = 0; i < s.size();i++){
            int c = s[i] - 'a';

            if(left[c] == -1) left[c] = i;//this store the first index of element which occure the firs

            right[c] = i;//this store the right most index
        }


        int ans = 0;//this store the index
        for(int i = 0; i < 26; i ++){
            if(left[i] == -1 || left[i] == right[i]) continue;//if the element is not present or the have the same starting and the endigng index , means only one element is present of it

            unordered_set<char> mid;//this is use to use the unique element which can form the palindrome

            for(int k = left[i] + 1; k < right[i]; k++){
                mid.insert(s[k]);//insert each unique element
            }
            ans += mid.size();//add the size , means the number of unique element 

        }
        return ans;

    }
};