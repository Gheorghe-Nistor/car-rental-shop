//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_CUSTOMER_H
#define MAIN_CPP_CUSTOMER_H

using std::string;

class Customer{
    static int indexID;
    const int ID;
    string first_name;
    string last_name;
    int age;
    char* occupation;
};
int Customer::indexID = 0;

#endif //MAIN_CPP_CUSTOMER_H
