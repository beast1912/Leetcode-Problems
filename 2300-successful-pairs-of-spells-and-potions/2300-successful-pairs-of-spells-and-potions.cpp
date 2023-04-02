class Solution
{
    private:
        int binary_search(vector<int> &potions, long long spell, long long success)
        {
            int low = 0;
            int high = potions.size() - 1;
            int ans = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                long long prod = spell *potions[mid];
                if (prod >= success)
                {
                    ans = mid;
                    high = mid - 1;
                }
                else if (prod < success)
                    low = mid + 1;
            }
            return ans;
        }
    public:
        vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
        {
            int n = potions.size();
            sort(potions.begin(), potions.end());
            vector<int> pairs;
            for (int i = 0; i < spells.size(); i++)
            {
                int pos = binary_search(potions, spells[i], success);
                if (pos == -1)
                    pairs.push_back(0);
                else
                    pairs.push_back(n - pos);
            }
            return pairs;
        }
};