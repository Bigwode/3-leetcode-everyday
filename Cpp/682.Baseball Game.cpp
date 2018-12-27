class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        int nums = 0, score = 0;
        vector<int> s;
        for(string op : ops)
        {
            if (op == "C")
            {
                nums -= s.back();
                s.pop_back();
                continue;
            }
            else if (op == "D")
            {
                score = s.back() * 2;
                nums += score;
            }
            else if (op == "+")
            {
                score = s[s.size()-1] + s[s.size()-2];
                nums += score;
            }
            else{
                score = stoi(op);
                nums += score;
            }
            s.push_back(score);
        }
        return nums;
    }
};
