#include "hybridSort.hpp"
#include <iostream>
using ll = long long;
using namespace std;

int main()
{

    vector<int> sample = {3, 7, 8, 1, 2, 0, 4, 6};
    ll comparisons = 0;
    int s = 4;

    hybridSort(sample, 0, sample.size() - 1, comparisons, s);

    for (int num : sample)
        cout << num << " ";
    cout << endl
         << comparisons;
}