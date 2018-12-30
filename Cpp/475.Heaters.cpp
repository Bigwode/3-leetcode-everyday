class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        int len = heaters.size(), j = 0, res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i =0; i<houses.size(); i++)
        {
            int cur = houses[i];
            while(j<len-1 && abs(heaters[j+1]-cur) <= abs(heaters[j]-cur))
                j++;
            res = max(res, abs(heaters[j]-cur));
        }
        return res;
    }
};
