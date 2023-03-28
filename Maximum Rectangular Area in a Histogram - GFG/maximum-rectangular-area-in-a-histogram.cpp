//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<long long> NSL(long long arr[], int n)
    {
        stack<pair<long, long>> s;
        vector<long long> ans;
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

    vector<long long> NSR(long long arr[], int n)
    {
        stack<pair<long, long>> s;
        vector<long long> ans;
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
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
            vector<long long> left = NSL(arr, n);
            vector<long long> right = NSR(arr, n);
            vector<long long> width(n), area(n);

            for (int i = 0; i < n; i++)
            {
                width[i] = right[i] - left[i] - 1;
                area[i] = arr[i] *width[i];
            }

            long long max_area = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                max_area = max(max_area, area[i]);
            }
            return max_area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends