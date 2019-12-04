#include <iostream>
#include <vector>
#include <string>

using namespace std;

int for_loop_pre(int max_iteration) {
    for (int i = 1; i <= max_iteration; ++i) {
        cout << i << endl;
    }
    return NULL;
}

int for_loop_post(int max_iteration) {
    for (int i = 1; i <= max_iteration; i++) {
        cout << i << endl;
    }
    return NULL;
}

int for_loop_arr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }
    return NULL;
}

int for_loop_vec(vector<string> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] <<endl;
    }
    return NULL;
}

int for_loop_multiple_var(int num1, int num2) {
    for (int i = 0, j = 0; i < num1, j < num2; i++, j++) {
        cout << "(" << i << "," << j << ")" << endl;
    }
    return NULL;
}
int main() {

    int max;
    cout << "Enter the max number of iterations: ";
    cin >> max;

    cout << "Prefix Increment Loop" << endl;
    cout << "=====================" << endl;
    for_loop_pre(max);
    cout << "Postfix Increment Loop" << endl;
    cout << "=====================" << endl;
    for_loop_post(max);

    int arr[] = {11,12,13,14,15};
    for_loop_arr(arr, 5);
    cout << endl;
    
    vector<string> vec {"aesad","bdasdad","ctasdasd"};
    for_loop_vec(vec);
    cout << endl;

    int num1, num2; 
    num1 = num2 = 5;
    for_loop_multiple_var(num1, num2);
    return 0;
}