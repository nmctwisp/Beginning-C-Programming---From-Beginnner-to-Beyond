#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    char choice;

    do {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'p':
            case 'P':
                cout << "[ ";
                for (size_t elm: vec)
                    cout << elm << " ";
                cout << "]" << endl;
                break;
            case 'a':
            case 'A': {
                int elm;
                cout << "Enter a number: ";
                cin >> elm;
                vec.push_back(elm);
                break;
            }
            case 'm': 
            case 'M': {
                int total;
                for (size_t elm: vec)
                    total += elm;
                cout << static_cast<double>(total)/vec.size() << endl;
                break;
            }
            case 's': 
            case 'S': {
                int smallest {0};
                int current {0};
                for (size_t i=0; i < vec.size(); ++i) {
                    int index = i;
                    current = vec.at(index);
                    if (index == 0)
                        smallest = current;
                    else if (current < smallest)
                        smallest = current;
                }
                cout << smallest << endl;
                break;   
            }
            case 'l': 
            case 'L': {
                int largest {0};
                int current {0};
                for (size_t i=0; i < vec.size(); ++i) {
                    int index = i;
                    current = vec.at(index);
                    if (index == 0)
                        largest = current;
                    else if (current > largest)
                        largest = current;
                }
                cout << largest << endl;
                break;
            }
            default:
                cout << "Goodbye!" << endl;         
        }
    
    cout << endl;

    } while (choice != 'Q' && choice != 'q');
    
    return 0;
}