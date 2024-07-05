#include <iostream>
#include <vector>
using namespace std;

bool bingo(vector<vector<bool> > &bb);

int main()
{
    int times;
    cin >> times;
    while (times-- > 0)
    {
        vector<vector<int> > vv(5);
        vector<vector<bool> > bb(5);
        int n, result = 0;

        for (int i = 0; i < 5; i++)
        {
            vv[i].resize(5);
            bb[i].resize(5, false);
        }

        bb[2][2] = true;

        for (int i = 0; i < 5; i++)
        {
            if (i == 2)
            {
                for (int j = 0; j < 2; j++)
                {
                    cin >> n;
                    vv[i][j] = n;
                }
                for (int j = 3; j < 5; j++)
                {
                    cin >> n;
                    vv[i][j] = n;
                }
            }
            else
            {
                for (int j = 0; j < 5; j++)
                {
                    cin >> n;
                    vv[i][j] = n;
                }
            }
        }
        int ans, real_result = 0;
        bool stop = false;
        for (int i = 0; i < 75; i++)
        {
            cin >> ans;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (vv[i][j] == ans)
                        bb[i][j] = true;
                }
            }
            result++;
            if (bingo(bb) && !real_result)
            {
                real_result = result;
                stop = true;
            }
        }
        cout << "BINGO after " << real_result << " numbers announced" << endl;

        // for(int i = 0; i < 5; i++){
        //     for(int j = 0; j < 5; j++){
        //         cout << vv[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vv.clear();
    }
    return 0;
}

bool bingo(vector<vector<bool> > &bb)
{
    int time = 0;

    for (int i = 0; i < 5; i++)
    {
        time = 0;
        for (int j = 0; j < 5; j++)
        {
            if (bb[i][j] == true)
                time++;
        }
        if (time == 5)
            return true;
    }

    for (int i = 0; i < 5; i++)
    {
        time = 0;
        for (int j = 0; j < 5; j++)
        {
            if (bb[j][i] == true)
                time++;
        }
        if (time == 5)
            return true;
    }

    time = 0;
    for (int i = 0; i < 5; i++)
    {
        if (bb[i][i] == true)
            time++;
    }
    if (time == 5)
        return true;

    if (bb[0][4] && bb[1][3] && bb[3][1] && bb[4][0])
        return true;

    return false;
}