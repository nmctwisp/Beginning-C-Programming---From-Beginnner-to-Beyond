#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int main() {
    // EXAMPLE 1
    int score = 100; // container
    int *score_ptr = &score;

    // *pointer.value = container.value
    cout << "pointer.dereferenced_value = " << *score_ptr << endl; // 100
    cout << "container.value = " << score << endl; // 100
    
    // pointer_value = container.address 
    cout << "container.address = " << &score << endl;
    cout << "pointer.value = " << score_ptr << endl;
    
    // the pointer has it's own memory address
    cout << "pointer.address = " << &score_ptr << endl;

    *score_ptr = 200;

    cout << "\npointer.dereferenced_value = " << *score_ptr << endl; // 22100
    cout << "score.value = " << score << endl; // 200
    cout << "score.address = " << &score << endl;
    cout << "Pointer.value = " << score_ptr << endl;
    cout << "pointer.address = " << &score_ptr << endl;
    cout << endl;

}
