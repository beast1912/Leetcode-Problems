class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>u;
        for(int i = 0; i < nums.size(); i++)
        {
            u[nums[i]]++;
        }
        int element;
        for(auto i: u)
        {
            if(i.second == 1)
                element = i.first;
        }
        return element;
    }
};