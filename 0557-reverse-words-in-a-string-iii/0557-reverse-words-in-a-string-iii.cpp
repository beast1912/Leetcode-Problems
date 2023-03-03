class Solution
{
    public:
        void reverse(string &s, int i, int j)
        {
            while (i < j)
            {
                swap(s[i++], s[j--]);
            }
        }
    string reverseWords(string s)
    {
        int i = 0;
        int n = s.size();
        int start = 0;
        int index = 0;
        while (i <= n)
        {
            if (s[i] == ' ' || i == n)
            {
                int end = i - 1;
                reverse(s, start, end);
                start = i + 1;
            }
            i++;
        }
        return s;
    }
};