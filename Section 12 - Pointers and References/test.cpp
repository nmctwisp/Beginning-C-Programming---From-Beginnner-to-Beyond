#include <iostream>

using namespace std;

int *apply_all(int array1[], const size_t array_size1, int array2[], const size_t array_size2) {

    size_t new_arr_size = (array_size1 * array_size2);
    int *new_arr = new int[new_arr_size];
    int n = 0;
    for (size_t i=0; i<array_size1; ++i){
        for (size_t j=0; j<array_size2; ++j){
            *(new_arr + n) = array1[i] * array2[j];
            n++;

        }
    }
    return new_arr;
}

void print(const int array[], const size_t array_size) {
    for (size_t i=0; i<array_size; ++i){
        cout << *(array + i) << endl;
    }
}

int main() {
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {1,2,3,4,5,6};
    int *result = apply_all(arr1, 6, arr2, 6);

    for (int i=0; i<36; ++i)
        cout << *(result + i) << endl;
    return 0;
}