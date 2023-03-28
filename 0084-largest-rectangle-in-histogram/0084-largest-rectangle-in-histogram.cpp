class Solution
{

    private:
        vector<int> NSL(vector<int> &arr, int n)
        {
            stack<pair<int, int>> s;
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                if (s.empty())
                    ans.push_back(-1);
                else if (s.top().first < arr[i])
                    ans.push_back(s.top().second);
                else if (s.top().first >= arr[i])
                {
                    while (!s.empty() && s.top().first >= arr[i])
                    {
                        s.pop();
                    }
                    if (s.empty())
                    {
                        ans.push_back(-1);
                    }
                    else
                        ans.push_back(s.top().second);
                }
                s.push({arr[i], i});
            }
            return ans;
        }

    vector<int> NSR(vector<int> &arr, int n)
    {
        stack<pair<int, int>> s;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
                ans.push_back(n);
            else if (s.top().first < arr[i])
                ans.push_back(s.top().second);
            else if (s.top().first >= arr[i])
            {
                while (!s.empty() && s.top().first >= arr[i])
                {
                    s.pop();
                }
                if (s.empty())
                {
                    ans.push_back(n);
                }
                else
                    ans.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    public:
        int largestRectangleArea(vector<int> &heights)
        {
            int n = heights.size();
            vector<int> left = NSL(heights, n);
            vector<int> right = NSR(heights, n);
            vector<int> width(n), area(n);

            for (int i = 0; i < n; i++)
            {
                width[i] = right[i] - left[i] - 1;
                area[i] = heights[i] *width[i];
            }

            int max_area = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                max_area = max(max_area, area[i]);
            }
            return max_area;
        }
};