/*
Problem Name: Resistor Time Machine

Short Problem Statement:
Mike has an unlimited number of unit resistors (R0 = 1). Using series and parallel
connections, he wants to construct an equivalent resistance equal to a/b.
The task is to find the minimum number of unit resistors required to obtain
the resistance a/b.

Approach (Using Prefix Sums / Euclidean Algorithm Insight):
The process of building resistance values using series (+1) and parallel
(R / (R + 1)) operations mirrors the steps of the Euclidean Algorithm.
At each step:
- We can add as many series resistors as possible (a / b)
- Reduce the fraction using modulo
- Swap roles of numerator and denominator

The total number of operations corresponds to the total number of unit
resistors required.

This is equivalent to summing all quotients in the Euclidean Algorithm.

Time Complexity:
O(log(min(a, b)))

Space Complexity:
O(1)

Example:
Input: 3 2
Process:
3/2 -> 1 + 1/2
1/2 -> parallel construction
Total resistors used = 3

Submission Link:
https://codeforces.com/submissions/amansharma264
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio();

    long long a, b;
    cin >> a >> b;

    long long ans = 0;

    while (b != 0) {
        ans += a / b;
        a %= b;
        swap(a, b);
    }

    cout << ans << '\n';
    return 0;
}
