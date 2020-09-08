class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> mp, mp2;
        for (int i = 0; i < s.length(); i++)
        {
            if (!mp[s[i]] && !mp2[t[i]])
            {
                mp[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            else if (mp[s[i]] == t[i] || mp2[t[i]] == s[i])
                continue;
            else
                return false;
        }
        return true;
    }
};