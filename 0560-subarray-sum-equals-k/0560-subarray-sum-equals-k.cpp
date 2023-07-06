class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int> u;
        u[0] = 1;
        int prefix_sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            prefix_sum += nums[i];
            int rem = prefix_sum - k;
            count += u[rem];
            u[prefix_sum]++;
        }
        return count;
    }
};