/*
排好序的二维数组中元素的查找
需要从右上角或者左下角开始找
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) 
    {
        int row  = 0;
        int col  = array[0].size()-1;
        while(row<array.size() && col>=0)
        {
            if(array[row][col] == target)
                return true;
            else if(array[row][col] > target)
                --col;
            else
                ++row;
        }
        return false;
    }
};
