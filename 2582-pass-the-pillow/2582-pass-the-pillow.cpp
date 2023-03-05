class Solution
{
    public:
        int passThePillow(int n, int time)
        {
            bool going_right = true;
            int i = 1;
            while (time--)
            {
                if (going_right)
                    i++;
                else
                    i--;
                if (i == 1 || i == n)
                    going_right = !going_right;
            }
            return i;
        }
};