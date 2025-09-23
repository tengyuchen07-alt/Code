// Polynomial division
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividendDegree >= divisorDegree, and
// neither dividend nor divisor is the zero polynomial
void division(int dividend[], int divisor[], int quotient[], int remainder[],
    int dividendDegree, int divisorDegree, int& quotientDegree, int& remainderDegree);

const int arraySize = 101;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int dividend[arraySize];
        int dividendDegree;
        cin >> dividendDegree;
        for (int i = dividendDegree; i >= 0; i--)
            cin >> dividend[i];

        int divisor[arraySize];
        int divisorDegree;
        cin >> divisorDegree;
        for (int i = divisorDegree; i >= 0; i--)
            cin >> divisor[i];

        int quotient[arraySize];
        int remainder[arraySize];
        int quotientDegree;
        int remainderDegree;
        division(dividend, divisor, quotient, remainder,
            dividendDegree, divisorDegree, quotientDegree, remainderDegree);

        cout << quotientDegree;
        for (int i = quotientDegree; i >= 0; i--)
            cout << " " << quotient[i];
        cout << endl;

        cout << remainderDegree;
        for (int i = remainderDegree; i >= 0; i--)
            cout << " " << remainder[i];
        cout << endl;
    }
}

// quotient = dividend / divisor; remainder = dividend % divisor
// provided that dividendDegree >= divisorDegree, and
// neither dividend nor divisor is the zero polynomial
void division(int dividend[], int divisor[], int quotient[], int remainder[],
    int dividendDegree, int divisorDegree, int& quotientDegree, int& remainderDegree)
{
    quotientDegree = dividendDegree - divisorDegree;
    int current_r[101];
    for (int i = 0; i <= dividendDegree; i++) {
        current_r[i] = dividend[i];
    }
    int dend = dividendDegree, sor = divisorDegree;
    for (int i = quotientDegree; i>=0; i--,dend--) {
        quotient[i] = current_r[dend] / divisor[sor];
        for (int m = dend,n=sor; n >= 0; m--,n--) 
            current_r[m] = current_r[m] - quotient[i] * divisor[n];
    }
    remainderDegree = dividendDegree;
    while (current_r[remainderDegree] == 0)remainderDegree--;
    if (remainderDegree < 0) {
        remainderDegree = 0;
        remainder[0] = 0;
    }
    else
        for (int i = 0; i <= remainderDegree; i++) remainder[i] = current_r[i];
}