#include <iostream>
#include "StringData.h"
#include <string>
#include <vector>
#include <string.h>

using namespace std;
using namespace std::chrono;

int linear_search(vector<string> vec, string element) {
    for (int i=0; i<vec.size(); i++)
        if (vec[i] == element)
            return i;

    return -1;
}

int binary_search(vector<string> vec, string element) {
    int start = 0;
    int end = vec.size();
    while(start <= end) {
        int mid = (start + end)/2;
        if (vec[mid] < element)
            start = mid + 1;
        else if (vec[mid] > element)
            end = mid-1;
        else
            return mid;
    }
}

int main() {
    vector<string> tup = getStringData();
    auto start = std::chrono::system_clock::now();
    cout << "linear search: " << linear_search(tup, "not_here") << endl;
    auto end = std::chrono::system_clock::now();
    cout << "diff in time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << endl;

    start = std::chrono::system_clock::now();
    cout << "binary search: " << binary_search(tup, "not_here") << endl;
    end = std::chrono::system_clock::now();
    cout << "diff in time: " << chrono::duration_cast<chrono::microseconds>(end-start).count() << endl;

}
