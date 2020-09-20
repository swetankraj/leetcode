class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        vector<int> direction = {0, 1};
        vector<int> position = {0, 0};

        for (auto x : instructions)
        {
            if (x == 'G')
            {
                position[0] += direction[0];
                position[1] += direction[1];
            }
            else if (x == 'L')
            {
                int i = direction[0];
                int j = direction[1];

                direction[0] = -j;
                direction[1] = i;
            }
            else if (x == 'R')
            {
                int i = direction[0];
                int j = direction[1];

                direction[0] = j;
                direction[1] = -i;
            }
        }

        return (position[0] == 0 && position[1] == 0) || (direction[0] != 0 || direction[1] != 1);
    }
};