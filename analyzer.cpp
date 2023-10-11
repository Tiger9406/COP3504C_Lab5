#include <iostream>
#include "StringData.h"
#include <string>

using namespace std;



int linear_search(vector<string> container, string element){
    for(int i = 0; i < container.size(); i++){
        if(element==container[i]){
            return i;
        }
    }
    return -1;
}

int binary_search(vector<string> container, string element){
    int left = 0;
    int right = container.size()-1;
    while(left <= right){
        int mid=(left+right)/2;
                if(container[mid]==element){
                    return mid;
                }
                if(container[mid]<element){
                    left = mid+1;
                }
                else if(container[mid]>element){
                    right = mid-1;
                }
    }
    return -1;
}

int main() {
    vector<string> s = getStringData();

    cout << "Linear for not_here: ";
    auto now = chrono::system_clock::now();
    cout << linear_search(s, "not_here") << endl;
    auto now2 = chrono::system_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(now2 - now).count() <<endl;

    cout << "Binary for not_here: ";
    now = chrono::system_clock::now();
    cout << binary_search(s, "not_here") << endl;
    now2 = chrono::system_clock::now();
    cout << chrono::duration_cast<std::chrono::milliseconds>(now2 - now).count() <<endl;

    cout << "Linear for mzzzz: ";
    now = chrono::system_clock::now();
    cout << linear_search(s, "mzzzz") << endl;
    now2 = chrono::system_clock::now();
    cout << chrono::duration_cast<std::chrono::milliseconds>(now2 - now).count() <<endl;

    cout << "Binary for mzzzz: ";
    now = chrono::system_clock::now();
    cout << binary_search(s, "mzzzz") << endl;
    now2 = chrono::system_clock::now();
    cout << chrono::duration_cast<std::chrono::milliseconds>(now2 - now).count() <<endl;

    cout << "Linear for aaaaa: ";
    now = chrono::system_clock::now();
    cout << linear_search(s, "aaaaa") << endl;
    now2 = chrono::system_clock::now();
    cout << chrono::duration_cast<std::chrono::milliseconds>(now2 - now).count() <<endl;

    cout << "Binary for aaaaa: ";
    now = chrono::system_clock::now();
    cout << binary_search(s, "aaaaa") << endl;
    now2 = chrono::system_clock::now();
    cout << chrono::duration_cast<std::chrono::milliseconds>(now2 - now).count() <<endl;
    return 0;
}