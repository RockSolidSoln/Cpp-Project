#include <iostream>
#include <vector>
#include <iomanip>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::setw;

constexpr int SIZE = 4;

int **ModifyArr2(int *arr, int len)
{
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j)
            *(arr + (i * len) + j) *= 2;
    }
    return reinterpret_cast<int **>(arr);
}

int main(){
    int c_array[SIZE][SIZE] = {{ 1, 2, 3, 4 },
                               { 5, 6, 7, 8 },
                               { 9, 10, 11, 12 },
                               { 13, 14, 15, 16 }};

    cout << "input array\n";
    for (auto & i : c_array) {
        cout << " [ ";
        for (int j : i) {
            cout << setw(2) << j << ", ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    int **ptr2 = ModifyArr2(c_array[0], SIZE);

    cout << "modified array\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << " [ ";
        for (int j = 0; j < SIZE; ++j) {
            cout << setw(2) << *((int*)ptr2 + (i * SIZE) + j) << ", ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    return EXIT_SUCCESS;
}