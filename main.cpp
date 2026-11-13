#include <iostream>
using namespace std;
long long mults = 0; // counts multiplications
long long calls = 0; // counts function calls
// Linear power: x^n = x * x^(n-1)
long long powerLinear(long long x, int n) {
calls++;
if (n == 0) return 1; // base case
mults++;
return x * powerLinear(x, n - 1); // recursive
}
// Fast power: x^n = (x^(n/2))^2, times x if n is odd
long long powerFast(long long x, int n) {
calls++;
if (n == 0) return 1; // base case
long long half = powerFast(x, n / 2); // one call on half the size
mults++;
long long result = half * half;
if (n % 2 == 1) { // n odd: one more
    mults++;
result = result * x;
}
return result;
}
int main() {
long long x;
int n;
cout << "Enter x and n: ";
cin >> x >> n;
mults = 0; calls = 0;
long long p1 = powerLinear(x, n);
cout << "Linear: " << x << "^" << n << " = " << p1
<< ", multiplications = " << mults << ", calls = " << endl;
return 0;
}