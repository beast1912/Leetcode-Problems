class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int n = chars.size();
            int ans_index = 0;
            for (int i = 0; i < n;)
            {
                int j = i + 1;
                while (j < n && chars[i] == chars[j])
                {
                    j++;
                }
                chars[ans_index++] = chars[i];
                int count = j - i;
                if (count > 1)
                {
                    string temp = to_string(count);
                    for (char c: temp)
                    {
                        chars[ans_index++] = c;
                    }
                }
                i = j;
            }
            return ans_index;
        }
};