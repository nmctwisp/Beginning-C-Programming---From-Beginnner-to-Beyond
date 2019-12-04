#include <iostream>
#include <vector>

using namespace std;

void print_numbers(const vector<int> vec);
void add_numbers(vector<int> &vec);
double get_mean(const vector<int> vec);
int min(const vector<int> vec);
int max(const vector<int> vec);

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
                print_numbers(vec);
                break;
            case 'a':
            case 'A':
                add_numbers(vec);
                break;
            case 'm': 
            case 'M': 
                cout << get_mean(vec) << endl;
                break;
            case 's': 
            case 'S':
                cout << min(vec) << endl;
                break;   
            case 'l': 
            case 'L': 
                cout << max(vec) << endl;
                break;
            default:
                cout << "Goodbye!" << endl;         
        }
    
    cout << endl;

    } while (choice != 'Q' && choice != 'q');
    
    return 0;
}

void print_numbers(const vector<int> vec) {
    cout << "[ ";
    for (int elm: vec)
        cout << elm << " ";
    cout << "]" << endl;
}

void add_numbers(vector<int> &vec) {
    int elm;
    cout << "Enter a number: ";
    cin >> elm;
    vec.push_back(elm);
}

double get_mean(const vector<int> vec) {
    int total{};
    for (int elm: vec)
        total += elm;
    return static_cast<double>(total)/vec.size();
}

int min(const vector<int> vec) {
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
    return smallest;
}

int max(const vector<int> vec) {
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
    return largest;
}
