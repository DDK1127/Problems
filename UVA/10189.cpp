#include<iostream>
using namespace std;
int r, c;

char Minesweeper(char **M, int i, int j){
    int bomb = 48;
    if(M[i][j] == '*'){return M[i][j];}
    else{
        for(int a = i-1; a <= i+1; a++){
            for(int b = j-1; b <= j+1; b++){
                if(a < 0 || a >= r || b < 0 || b >= c){}
                else if(M[a][b] == '*')
                        bomb++;
            }
        }
    }
    return (char)bomb;
}
int main(){
    char w;
    int times = 1;
    while(cin >> r >> c){
        if(r == 0 && c == 0)
            break;

        char **M = new char*[r];
        for(int i = 0; i < r; i++){
            M[i] = new char[c];
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> w;
                M[i][j] = w;
            }
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                M[i][j] = Minesweeper(M, i,j);
            }
        }
        if(times != 1)
            cout << endl;
        cout << "Field #" << times++ << ":" << endl;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << M[i][j];
            }
            cout << endl;
        }
        
        for(int i = 0; i < r; i++)
            delete[] M[i];
        delete[] M;
        
    }
    return 0;
}

