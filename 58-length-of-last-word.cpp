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