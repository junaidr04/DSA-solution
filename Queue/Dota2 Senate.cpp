class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> Radiant, Dire;
        int n = senate.size();
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
                Radiant.push(i);
            else
                Dire.push(i);
        }
        while (!Radiant.empty() && !Dire.empty())
        {
            int Rind = Radiant.front();
            Radiant.pop();
            int Dind = Dire.front();
            Dire.pop();
            if (Rind < Dind)
            {
                Radiant.push(Rind + n);
            }
            else
            {
                Dire.push(Dind + n);
            }
        }
        if (!Radiant.empty())
            return "Radiant";
        else
            return "Dire";
    }
};