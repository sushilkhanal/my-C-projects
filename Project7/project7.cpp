#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

int main()
{
    stack st; //object of the class type
    int num; //integer
    cout << "Enter a positive integer(0 to stop):";
    cin >> num; //enter an integer to find its prime factor
    while (st.is_InputValid(num) == true) //finds the prime factors of integer until true
    {
        if (num == 1) {
            cout << " Prime factors: " << num << " = ";
            cout << num << " " << endl;
        }
        else if (num > 1) {
            cout << " Prime factors: " << num << " = ";
            st.prime_factor(num);
            cout << st << endl;
        }
        else {
            break; //stop if the input is less than or equal to 0
        }
        cout << endl;
        cout << "Enter the positive integer(0 to stop): ";
        cin >> num; //takes another integer until the condition is true
    } //while

    return 0;
}
