#include <iostream>
#include <iomanip>
using namespace std;

int function_activation_count {0};

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION PROTOTYPE BELOW THIS LINE----

double a_penny_doubled_everyday(int n, double money=0.01);//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES

//----WRITE THE FUNCTION PROTOTYPE ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----

void amount_accumulated() {
    
//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION CALL BELOW THIS LINE----
    double total_amount = a_penny_doubled_everyday(25);

    
    
//----WRITE THE FUNCTION CALL ABOVE THIS LINE----
//----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout <<  "If I start with a penny and doubled it every day for 25 days, I will have $" << setprecision(10) << total_amount;
}

//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE THE FUNCTION DEFINITION BELOW THIS LINE----

double a_penny_doubled_everyday(int n, double money) {//----WRITE THE FUNCTION PARAMETER LIST WITHIN THE PARENTHESES
    function_activation_count++;
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE THE FUNCTION BODY BELOW THIS LINE----
    if (n <= 1) {
        return money;
    }
    return a_penny_doubled_everyday(--n, money * 2);
    
    //----WRITE THE FUNCTION BODY ABOVE THIS LINE----
    //DO NOT MODIFY THE CODE BELOW THIS LINE----
}

int test_function_activation_count() {
    return function_activation_count;
}

int main() {
    amount_accumulated();
    cout << test_function_activation_count();
    return 0;
}