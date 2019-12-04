#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<int> vector1;
    vector<int> vector2;
    cout << vector1.at(0) << " " << vector1.at(1) << endl;
    cout << vector1.size() << endl;

    vector1.push_back(10);
    vector1.push_back(20);
    cout << vector2.at(0) << " " << vector2.at(1) << endl;
    cout << vector2.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);


    vector<vector<int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    cout << vector_2d.size() << endl;
    
    //vector1[0] = 1000;
    vector1.at(0) = 1000;

    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    cout << vector1.at(0) << " " << vector1.at(1) << endl;

    return 0;
}