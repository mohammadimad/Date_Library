#include <iostream>
#include <string >
#include "clsDate.h";
using namespace std;
int main(void) {
    clsDate Date1;
    clsDate Date2("24/12/2004");
    cout << clsDate::CalculateMyAgeInDays(clsDate("24/12/2004"));
    return 0;
}