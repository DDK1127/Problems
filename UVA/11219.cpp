#include<iostream>
#include<math.h>
using namespace std;

int main(){
    string str1, str2;
    int times, result, n = 0;
    int d1, m1, y1, d2, m2, y2;
    cin >> times;

    while(n++ < times){
        cin >> str1;
        cin >> str2;
        d1 = 10*(int)((str2[0])-48) + (int)str1[1]-48;
        d2 = 10*(int)((str2[0])-48) + (int)str2[1]-48;
        m1 = 10*(int)((str1[3])-48) + (int)str1[4]-48;
        m2 = 10*(int)((str2[3])-48) + (int)str2[4]-48;
        y1 = 0 , y2 = 0;
        for(int i = 6; i < max(str1.size(), str2.size()); i++){
            y1 += pow(10,max(str1.size(), str2.size())-i-1)*(int)((str1[i])-48);
            y2 += pow(10,max(str1.size(), str2.size())-i-1)*(int)((str2[i])-48);
        }

        // cout << d1 << '/' << m1 << '/' << y1 << endl;
        // cout << d2 << '/' << m2 << '/' << y2 << endl;

        result = y1-y2;
        if(m1 < m2){result--;}
        else if(m1 == m2){
            if(d1 < d2)
                result--;
        }
            
        cout << "Case #" << n <<": ";
        if(result < 0)
            cout << "Invalid birth date" << endl;
        else if(result > 130)
            cout << "Check birth date" << endl;
        else
            cout << result << endl;
    }
    return 0;
}
/*
2002/11/27
19 v.s 20 v.s 20
2022/10/27 v.s 2022/11/27 vs. 2022/11/28


*/