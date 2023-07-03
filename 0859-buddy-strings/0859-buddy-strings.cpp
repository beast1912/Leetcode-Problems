class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        if(s == goal)
        {
            vector<int>character_count(26, 0);
            for(int i = 0; i < s.size(); i++)
            {
                character_count[s[i] - 'a']++;
                if(character_count[s[i] - 'a'] == 2)
                    return true;
            }
            return false;
        }
        int index1 = -1, index2 = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]!=goal[i])
            {
                if(index1 == -1)
                    index1 = i;
                else if(index2 == -1)
                    index2 = i;
                else return false;
            }
        }
        if(index2 == -1)
            return false;
        return (s[index1] == goal[index2] && s[index2] == goal[index1]);
    }
};