#include <iostream>
#include <vector>
using namespace std;

// int Sum(int n);

int main() {
  int a = 0;

  while (cin >> a && a) {
    vector<int> v;

    while (a / 10 != 0) {
      v.push_back(a % 10);
      a /= 10;

      if (a / 10 == 0) {
        for (int i = 0; i < v.size(); i++) {
          a += v[i];
        }
        v.clear();
      }
    }
    cout << a << endl;
  }
  return 0;
}
// int Sum(int n){
//     int temp = n;
//     vector<int> arr;
//     while (n >= 10){
//         arr.push_back(n % 10);
//         n = n/10;
//         cout << "n = " << n << endl;
//     }
//     for(long i = 0; i < arr.size(); i++){
//         temp += arr[i];
//     }
//     cout << "temp = " << temp;
//     return temp;
// }
