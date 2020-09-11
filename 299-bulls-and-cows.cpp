class Solution
{
public:
    string getHint(string secret, string guess)
    {
        unordered_map<char, set<int>> mp;
        for (int i = 0; i < secret.size(); i++)
        {
            mp[secret[i]].insert(i);
        }

        int bull = 0, cow = 0;
        set<int> bulls_matched;
        for (int i = 0; i < guess.size(); i++)
        {
            char x = guess[i];
            if (mp[x].find(i) != mp[x].end())
            {
                bull++;
                mp[x].erase(i);
                bulls_matched.insert(i);
            }
        }

        for (int i = 0; i < guess.size(); i++)
        {
            if (bulls_matched.find(i) != bulls_matched.end())
                continue;
            else
            {
                char x = guess[i];
                if (mp[x].size() > 0)
                {
                    cow++;
                    mp[x].erase(mp[x].begin());
                }
            }
        }
        string ans = to_string(bull) + 'A' + to_string(cow) + 'B';
        return ans;
    }
};