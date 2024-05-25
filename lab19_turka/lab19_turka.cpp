#include <iostream>
#include <vector>

using namespace std;

template <typename T>

bool isInVector(T element, const vector<T>& vec) {

    return find(vec.begin(), vec.end(), element) != vec.end();
}

template <typename T>

int countUniqueElements(T a[], int m, T b[], int n) {

    vector<T> vecA(a, a + m);
    vector<T> vecB(b, b + n);
    vector<T> uniqueElements;

    for (const T& element : vecA) {

        if (!isInVector(element, vecB)) {

            uniqueElements.push_back(element);
        }
    }

    for (const T& element : vecB) {

        if (!isInVector(element, vecA)) {

            uniqueElements.push_back(element);
        }
    }

    return uniqueElements.size();
}

int main() {

    setlocale(LC_CTYPE, "ukr");

    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 4, 5, 6, 7, 8 };

    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    cout << "кiлькiсть унiкальних елементiв: " << countUniqueElements(a, m, b, n) << '\n';

    return 0;
}


