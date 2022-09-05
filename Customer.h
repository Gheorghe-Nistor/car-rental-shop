//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_CUSTOMER_H
#define MAIN_CPP_CUSTOMER_H

class Customer{
    static int indexID;
    const int ID;
    string f_name;
    string l_name;
    int age;
    char *occupation;
public:
    Customer();
    Customer(const string &f_name, const string &l_name, int age, char *occupation);
    Customer(const Customer &ob);
    Customer &operator=(const Customer &ob);
    ~Customer();

    friend istream &operator>>(istream &in, Customer &ob);
    friend ostream &operator<<(ostream &out, const Customer &ob);

    Customer& operator++();
    const Customer operator++(int);
    int operator+(const Customer& ob) const;
    int operator-(const Customer& ob) const;
    bool operator <=(const Customer& ob) const;
    bool operator ==(const Customer& ob);
    explicit operator int() const;

    int getID() const;
    const string &getFName() const;
    void setFName(const string &fName);
    const string &getLName() const;
    void setLName(const string &lName);
    int getAge() const;
    void setAge(int age);
    char *getOccupation() const;
    void setOccupation(char *occupation);
};
int Customer::indexID = 0;

Customer::Customer() : ID(indexID++) {
    this->f_name = "N/A";
    this->l_name = "N/A";
    this->age = 0;
    this->occupation = new char[strlen("N/A") + 1];
    strcpy(this->occupation, "N/A");
}
Customer::Customer(const string &f_name, const string &l_name, int age, char *occupation) : ID(indexID), f_name(f_name),
                                                                                            l_name(l_name), age(age) {
    this->occupation = new char[strlen(occupation) + 1];
    strcpy(this->occupation, occupation);
}
Customer::Customer(const Customer &ob) : ID(indexID++) {
    this->f_name = ob.f_name;
    this->l_name = ob.l_name;
    this->age = ob.age;
    this->occupation = new char[strlen(ob.occupation) + 1];
    strcpy(this->occupation, ob.occupation);
}
Customer &Customer::operator=(const Customer &ob) {
    if (this != &ob) {
        this->f_name = ob.f_name;
        this->l_name = ob.l_name;
        this->age = ob.age;
        delete[] this->occupation;
        this->occupation = new char[strlen(ob.occupation) + 1];
        strcpy(this->occupation, ob.occupation);
    }
    return *this;
}
Customer::~Customer() {
    if(this->occupation != nullptr)
        delete[] this->occupation;
}

istream &operator>>(istream &in, Customer &ob) {
    while(true) {
        try {
            cout << ">> First name: ";
            in >> ob.f_name;
            if (ob.f_name.find_first_not_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos)
                throw MyException();
            if(ob.f_name.size() == 1)
                throw 0;
            break;
        }
        catch (MyException& e) {
            cout << e.what() << '\n';
        }
        catch(int e) {
            cout << "Error! The length of the first name cannot be one! \n";
        }
    }
    while(true) {
        try {
            cout << ">> Last name: ";
            in >> ob.l_name;
            if (ob.l_name.find_first_not_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos)
                throw MyException();
            if(ob.l_name.size() == 1)
                throw 0;
            break;
        }
        catch (MyException& e) {
            cout << e.what() << '\n';
        }
        catch(int e) {
            cout << "Error! The length of the last name cannot be one! \n";
        }
    }
    while(true) {
        try {
            cout << ">> Age: ";
            in >> ob.age;
            if(in.fail()) {
                in.clear();
                in.ignore();
                throw runtime_error("Error! Age must contain only numeric characters.");
            }
            if (ob.age < 16)
                throw 0;
            break;
        }
        catch (runtime_error& e) {
            cout << e.what() << '\n';
        }
        catch (int e) {
            cout << "Error! The age of the customer cannot be younger than 16 years. \n";
        }
    }
    cout << ">> Occupation: ";
    delete[] ob.occupation;
    char s[50];
    in >> s;
    ob.occupation = new char[strlen(s) + 1];
    strcpy(ob.occupation, s);
    return in;
}
ostream &operator<<(ostream &out, const Customer &ob) {
    out << "ID: " << ob.ID << '\n';
    out << "First name: " << ob.f_name << '\n';
    out << "Last name: " << ob.l_name << '\n';
    out << "Age: " << ob.age << " years \n";
    out << "Occupation: " << ob.occupation << '\n';
    return out;
}

Customer& Customer::operator++(){
    this->age++;
    return *this;
}
const Customer Customer::operator++(int){
    Customer c = *this;
    this->age++;
    return c;
}
int Customer::operator+(const Customer& ob) const{
    return this->age+ob.age;
}
int Customer::operator-(const Customer& ob) const{
    return this->age-ob.age;
}
bool Customer::operator <=(const Customer& ob) const{
    return this->age <= ob.age;
}
bool Customer::operator ==(const Customer& ob){
    return this->age == ob.age && (strcmp(this->occupation, ob.occupation) == 0);
}
Customer::operator int() const{
    return (int) this->age;
}

int Customer::getID() const{
    return this->ID;
}
const string &Customer::getFName() const {
    return f_name;
}
void Customer::setFName(const string &fName) {
    f_name = fName;
}
const string &Customer::getLName() const {
    return l_name;
}
void Customer::setLName(const string &lName) {
    l_name = lName;
}
int Customer::getAge() const {
    return age;
}
void Customer::setAge(int age) {
    this->age = age;
}
char *Customer::getOccupation() const {
    return occupation;
}
void Customer::setOccupation(char *occupation) {
    this->occupation = new char[strlen(occupation) + 1];
    strcpy(this->occupation, occupation);
}
#endif //MAIN_CPP_CUSTOMER_H
