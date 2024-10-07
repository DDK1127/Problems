#include <bits/stdc++.h>
using namespace std;

int calculate_inversion(string s)
{
    if (s == "")
        return 0;
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] > s[j])
                sum++;
        }
    }
    return sum;
}

bool cmp(pair<string, pair<int, int> > p1, pair<string, pair<int, int> > p2)
{
    if (p1.second.first == p2.second.first)
        return p1.second.second < p2.second.second;
    else
        return p1.second.first < p2.second.first;
};

int main()
{
    int t, n, m, inver;
    string input;
    pair<string, int> p;
    pair<int, int> pp;
    vector<pair<string, pair<int, int> > > v;

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> input;
            inver = calculate_inversion(input);
            v.push_back(make_pair(input, make_pair(inver, i)));
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < m; i++)
            cout << v[i].first << endl;
        if (t)
            cout << endl;
        v.clear();
    }

    return 0;
}
