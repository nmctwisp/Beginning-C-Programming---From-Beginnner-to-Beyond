#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

int main() {
    double lowtemp = 37.4;
    double hightemp = 100.7;
    double *temp_ptr = &hightemp;


    double lukewarmtemp = 65; 

    cout << "temp_ptr.dereferenced_value = " << *temp_ptr << endl; // 100
    cout << "hightemp.value = " << hightemp << endl; // 100
    cout << "hightemp.address = " << &hightemp << endl;
    cout << "temp_ptr.value = " << temp_ptr << endl;
    cout << "temp_ptr.address = " << &temp_ptr << endl;
    cout << "lowtemp.value = " << lowtemp << endl;
    cout << "lowtemp.address = " << &lowtemp << endl;
    cout << "lukewarmtemp.value = " << lukewarmtemp << endl;
    cout << "lukewarmtemp.address = " << &lukewarmtemp << endl;

    temp_ptr+=1; // increments the address. this should only ever be done if you know what is in the immediate memory block 

    cout << "\ntemp_ptr.dereferenced_value = " << *temp_ptr << endl; // 100
    cout << "hightemp.value = " << hightemp << endl; // 100
    cout << "hightemp.address = " << &hightemp << endl;
    cout << "temp_ptr.value = " << temp_ptr << endl;
    cout << "temp_ptr.address = " << &temp_ptr << endl;
    cout << "lowtemp.value = " << lowtemp << endl;
    cout << "lowtemp.address = " << &lowtemp << endl;
    cout << "lukewarmtemp.value = " << lukewarmtemp << endl;
    cout << "lukewarmtemp.address = " << &lukewarmtemp << endl;

    *temp_ptr = lowtemp;

    cout << "\ntemp_ptr.dereferenced_value = " << *temp_ptr << endl; // 100
    cout << "hightemp.value = " << hightemp << endl; // 100
    cout << "hightemp.address = " << &hightemp << endl;
    cout << "temp_ptr.value = " << temp_ptr << endl;
    cout << "temp_ptr.address = " << &temp_ptr << endl;
    cout << "lowtemp.value = " << lowtemp << endl;
    cout << "lowtemp.address = " << &lowtemp << endl;
    cout << "lukewarmtemp.value = " << lukewarmtemp << endl;
    cout << "lukewarmtemp.address = " << &lukewarmtemp << endl;

    hightemp+=1;
    
    cout << "\ntemp_ptr.dereferenced_value = " << *temp_ptr << endl; // 100
    cout << "hightemp.value = " << hightemp << endl; // 100
    cout << "hightemp.address = " << &hightemp << endl;
    cout << "temp_ptr.value = " << temp_ptr << endl;
    cout << "temp_ptr.address = " << &temp_ptr << endl;
    cout << "lowtemp.value = " << lowtemp << endl;
    cout << "lowtemp.address = " << &lowtemp << endl;
    cout << "lukewarmtemp.value = " << lukewarmtemp << endl;
    cout << "lukewarmtemp.address = " << &lukewarmtemp << endl;

    lowtemp+=1;

    cout << "\ntemp_ptr.dereferenced_value = " << *temp_ptr << endl; // 100
    cout << "hightemp.value = " << hightemp << endl; // 100
    cout << "hightemp.address = " << &hightemp << endl;
    cout << "temp_ptr.value = " << temp_ptr << endl;
    cout << "temp_ptr.address = " << &temp_ptr << endl;
    cout << "lowtemp.value = " << lowtemp << endl;
    cout << "lowtemp.address = " << &lowtemp << endl;
    cout << "lukewarmtemp.value = " << lukewarmtemp << endl;
    cout << "lukewarmtemp.address = " << &lukewarmtemp << endl;

    temp_ptr = &lukewarmtemp;

    cout << "\ntemp_ptr.dereferenced_value = " << *temp_ptr << endl; // 100
    cout << "hightemp.value = " << hightemp << endl; // 100
    cout << "hightemp.address = " << &hightemp << endl;
    cout << "temp_ptr.value = " << temp_ptr << endl;
    cout << "temp_ptr.address = " << &temp_ptr << endl;
    cout << "lowtemp.value = " << lowtemp << endl;
    cout << "lowtemp.address = " << &lowtemp << endl;
    cout << "lukewarmtemp.value = " << lukewarmtemp << endl;
    cout << "lukewarmtemp.address = " << &lukewarmtemp << endl;
    return 0;
}
