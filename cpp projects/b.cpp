
#include <iostream>
using namespace std;

int test (int n){

    const int x = 51;
    
    if (n > x){
        return (n - x)*3;
    }

    return (n - x);
}

int main () {

    cout << test(53) << endl;
    cout << test(30) << endl;
    cout << test(51) << endl;
}