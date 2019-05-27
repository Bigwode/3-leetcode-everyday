class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int low = 0, high = letters.size(), mid;
        while(low<high)
        {
            mid = low + (high-low)/2;
            if (letters[mid] > target) high = mid;
            else low = mid+1;
        }
        
        if(high == letters.size())
            return letters[0];
        return letters[high];
    }
};
