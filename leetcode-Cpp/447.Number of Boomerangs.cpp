class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>> & points) 
    {
        int res = 0;

        for(auto &m :points)
        {
            int d = 0;
            map<int, int> dis;
            for(auto &n : points)
            {
                d = (m.first-n.first)*(m.first-n.first)+
                    (m.second-n.second)*(m.second-n.second);
                dis[d]++;
            }
            for(auto &mm : dis)
            {
                res += mm.second*(mm.second-1);
            }
        }
        
        return res;
    }
};
