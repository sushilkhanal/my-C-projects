#include <iostream>
#include <cstdlib>
using namespace std;
int pfactor(int f);
int main()
{
    int pnumber;
    cout << "Enter a positive integer: ";
    cin >> pnumber;
    cout << "The prime factors of " << pnumber << " are ";
    pfactor(pnumber);
    cout << endl;
}
int pfactor(int f)
{
    if (f == 1) {
        return 0;
    }
    else {
        int i = 2;
        while ((f % i) != 0) i++;
        cout << i << " ";
        pfactor(f / i);
    }
}
