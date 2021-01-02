class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0,even=0;
        for (int i:position)
        {
            if(i%2==0)
                even++;
            else
                odd++;
        }
        if(even==position.size() || odd==position.size()) return 0;
        return min(even,odd);
    }
};