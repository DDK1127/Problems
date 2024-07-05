#include <iostream>
using namespace std;
void Wave(int n);

int main()
{
    int times, a, f;
    cin >> times;
    for (int k = 1; k <= times; k++)
    {
        cin >> a >> f;
        for (int i = 1; i <= f; i++)
        {
            Wave(a);
            if (i == f && k == times){}
            else{cout << endl;}
        }
    }
    return 0;
}
void Wave(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << i;
        cout << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
            cout << i;
        cout << endl;
    }
}