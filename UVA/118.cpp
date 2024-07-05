#include<iostream>
using namespace std;

char rotation(char dir, char rotate);
int main(){
    int x, y, fall_number = 0;
    char dir;
    bool dropped, fall;
    string str;
    pair<int, int> b, start;
    pair<int, int> before[100];
    cin >> x >> y;
    b = make_pair(x, y);

    while((cin >> x >> y) && !cin.eof()){
        start = make_pair(x, y);
        cin >> dir;
        cin >> str;
        fall = false;
        for(int i = 0; i < str.size(); i++){
            dropped = false;

            if(str[i] == 'F'){
                if(dir == 'N')
                    start.second++;
                else if(dir == 'S')
                    start.second--;
                else if(dir == 'E')
                    start.first++;
                else if(dir == 'W')
                    start.first--;
            }
            else if(str[i] == 'L')
                dir = rotation(dir, 'L');
            else if(str[i] == 'R')
                dir = rotation(dir, 'R');

            if((start.first > b.first) || (start.first < 0) || (start.second > b.second) || (start.second < 0)){
                if(start.first > b.first)
                    start.first = b.first;
                else if(start.second > b.second)
                    start.second = b.second;
                else if(start.first < 0)
                    start.first = 0;
                else if(start.second < 0)
                    start.second = 0;

                for(int j = 0; j < fall_number; j++){
                    if(start.first == before[j].first && start.second == before[j].second)
                        dropped = true;
                }
                if(dropped == false){
                    before[fall_number++] = start;
                    fall = true;
                    cout << start.first << " " << start.second << " " << dir << " LOST" << endl;
                    break;
                }
            }
        }
        if(fall == false)
            cout << start.first << " " << start.second << " " << dir << endl;
    }
    return 0;
}
char rotation(char dir, char rotate){
    if((dir == 'N' && rotate == 'R') || (dir == 'S' && rotate == 'L'))
        dir = 'E';
    else if((dir == 'N' && rotate == 'L') || (dir == 'S' && rotate == 'R'))
        dir = 'W';
    else if((dir == 'E' && rotate == 'R') || (dir == 'W' && rotate == 'L')) 
        dir = 'S';
    else if((dir == 'E' && rotate == 'L') || (dir == 'W' && rotate == 'R'))
        dir = 'N';
    return dir;
}