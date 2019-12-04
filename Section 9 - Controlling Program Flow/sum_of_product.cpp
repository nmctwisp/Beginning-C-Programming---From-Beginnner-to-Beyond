#include <vector>
#include <iostream>
using namespace std;

int calculate_pairs(vector<int> vec) {
    //----WRITE YOUR CODE BELOW THIS LINE----
    int result = 0;
    for (size_t i=0; i < vec.size(); ++i) {
        for (size_t j=i+1; j < vec.size(); ++j){
            cout << vec.at(i) << " " << vec.at(j) << endl;
            result += vec.at(i) * vec.at(j);
        }
    }
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    return result;
}

int main() {
    vector<int> vec = {2, 4, 6, 8};

    cout << calculate_pairs(vec);

    return 0;
}