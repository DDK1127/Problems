#include <iostream>

using namespace std;

bool check(const string &str, int s)
{
    for (int i = 0; i < s; i++)
    {
        for (int j = i + s; j < str.size(); j += s)
        {
            if (str[i] != str[j])
                return false;
        }
    }
    return true;
}

int main()
{
    int times, n = 0;
    string str;
    cin >> times;

    while (n++ < times)
    {   
        if(n != 0)
            cout << endl;
        cin >> str;
        for (int i = 1; i <= str.size(); i++)
        {
            if (str.size() % i == 0 && check(str, i)){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}