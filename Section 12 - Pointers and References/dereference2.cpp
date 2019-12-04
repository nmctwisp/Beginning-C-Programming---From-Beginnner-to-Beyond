#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "Frank";
    string *string_ptr = &name;

    cout << "string_ptr.dereferenced_value = " << *string_ptr << endl;
    cout << "name.address = "<< &name <<" == string_ptr.value = " << string_ptr << endl; 
    cout << "string_ptr.address = " << &string_ptr << endl;
    
    
    name = "James";
    cout << "name variable changed to 'James'" << endl;
    
    cout << "string_ptr.dereferenced_value = " << *string_ptr << endl;
    cout << "name.address = "<< &name <<" == string_ptr.value = " << string_ptr << endl; 
    cout << "string_ptr.address = " << &string_ptr << endl;

    return 0;
}