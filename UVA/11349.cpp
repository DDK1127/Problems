#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int times;
    cin >> times;
    for(int k = 1; k <= times; k++)
    {
        int n;
        bool sym = true;
        scanf("\nN = %d", &n);


        vector<vector<long long> > vv(n, vector<long long>(n, 0));
        long long num;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> num;
                vv[i][j] = num;
                if(vv[i][j] < 0)
                    sym = false;
            }
        }
/*

* * * *
* * * * 
* * * * 
* * * * 

1,1 -> 2,2
*/



        int center = n/2;
        for (int i = 0; i < n; i++){
            if(!sym)
                break;
            for (int j = 0; j <= center; j++){
                if(vv[i][j] != vv[n-i-1][n-j-1] || vv[i][j] < 0 || vv[n-i-1][n-j-1] < 0){
                    sym = false;
                    break;
                }
            }
        }

        if(sym)
            cout << "Test #" << k << ": Symmetric." << endl;
        else
            cout << "Test #" << k << ": Non-symmetric." << endl;
    }

    return 0;
}
