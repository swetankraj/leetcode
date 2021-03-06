//* SEPTEMBER LEETCODE CHALLENGE 2020

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        bool space = false;
        string x = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' && x.length() > 0)
                space = true;
            else if (x.length() > 0 && space && s[i] != ' ')
            {
                x = s[i];
                space = false;
            }
            else if (!space && s[i] != ' ')
                x += s[i];
        }
        return x.length();
    }
};

// VERSION 2
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
        }
        return word.length();
    }
};

//VERSION 3
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size() - 1, s_len = 0;
        while (n >= 0)
        {
            if (s[n] != ' ')
                s_len++;
            else if (s[n] == ' ' && s_len > 0)
                return s_len;
            n--;
        }
        return s_len;
    }
};