// Transfers control to one of the several statements, depending on the value of a condition.
//
// Syntax
    // attr(optional) switch ( condition ) statement       (until C++17)
    // attr(optional) switch ( init-statement(optional) condition ) statement      (since C++17)
        // attr(C++11) -   any number of attributes
        // condition   -   any expression of integral or enumeration type, or of a class type contextually implicitly convertible to an integral or enumeration type, or a declaration of a single non-array variable of such type with a brace-or-equals initializer.
// init-statement(C++17)   -   either
    // - an expression statement (which may be a null statement ";")
    // - a simple declaration, typically a declaration of a variable with initializer, but it may declare arbitrary many variables or structured bindings
    // - Note that any init-statement must end with a semicolon ;, which is why it is often described informally as an expression or a declaration followed by a semicolon.
// statement   -   any statement (typically a compound statement). case: and default: labels are permitted in statement and break; statement has special meaning.

// attr(optional) case constant_expression : statement (1) 
// attr(optional) default : statement  (2) 
// constant_expression -   a constant expression of the same type as the type of condition after conversions and integral promotions

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

    int input_num;
    cout << "Pick a number between 1 and 10: ";
    cin >> input_num;
    
    //This following example is a typical use case for a switch statement

    switch (input_num) {
        case 1:
            cout << "You entered number 1.";
            break;
        case 2:
            cout << "You entered number 2.";
            break;
        case 3:
            cout << "You entered number 3.";
            break;
        case 4:
            cout << "You entered number 4.";
            break;
        case 5:
            cout << "You entered number 5.";
            break;
        case 6:
            cout << "You entered number 6.";
            break;
        case 7:
            cout << "You entered number 7.";
            break;
        case 8:
            cout << "You entered number 8.";
            break;
        case 9:
            cout << "You entered number 9.";
            break;
        case 10:
            cout << "You entered number 10.";
            break;
    }


    // This switch example uses the fall through logic of the switch 
    // statement. The fall through logic allows grouping cases together to
    // execute a common set of statements

    // switch (input_num) {
    //     case 1:
    //         cout << "Executing Case 1" << endl;
    //     case 3:
    //         cout << "Executing Case 3" << endl;
    //     case 5:
    //         cout << "Executing Case 5" << endl;
    //     case 7:
    //         cout << "Executing Case 7" << endl;            
    //         cout << input_num << " is an odd number that is also a prime number.";
    //         break;

    //     case 2:
    //     case 4:
    //     case 6:
    //     case 8:
    //     case 10:
    //         cout << input_num << " is a even number." << endl;
    //         break;

    //     default:
    //         cout << input_num << " is not handled by this switch statement";
    //     }    


    return 0;
}