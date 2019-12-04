#include <iostream>
#include <string>
using namespace std;

void cpp_strings() {
    
    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    journal_entry_1.erase(0, journal_entry_1.find(" ") + 1);
    
    if (journal_entry_1.at(0) > journal_entry_2.at(0)) 
        journal_entry_1.swap(journal_entry_2);
    
    
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << journal_entry_1 << "\n" << journal_entry_2;
}