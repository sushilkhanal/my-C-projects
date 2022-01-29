#include <iostream>
#include <cstdlib>
using namespace std;
int range(int low, int high);
int main()
{
    int x, y;
    cout << "Enter two integers, the first one being small than the second one.";
    cin >> x;
    cin >> y;
    int sumrange = range(x, y);
    cout << "The sum of the integers from " << x << " to " << y << " is: " << sumrange;
    cout << endl;
}
int range(int low, int high)
{
    if (low == high) {
        return low;
    }
    else {
        return low + range(low + 1, high);
    }
}