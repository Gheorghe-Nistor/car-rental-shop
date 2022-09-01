//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_MYEXCEPTION_H
#define MAIN_CPP_MYEXCEPTION_H

class MyException: public std::exception{
    char* message;
public:
    MyException();
    MyException(const char* message);
    MyException(const MyException& e);
    MyException& operator=(const MyException& e);
    virtual const char* what() const throw() {
        return message;
    }
    ~MyException();
};

MyException::MyException() {
    this->message = new char[strlen("Invalid input!")+1];
    strcpy(this->message, "Invalid input!");
}

MyException::MyException(const char* message) {
    this->message = new char[strlen(message)+1];
    strcpy(this->message, message);
}

MyException::MyException(const MyException &e) {
    this->message = new char[strlen(e.message)+1];
    strcpy(this->message, e.message);
}

MyException& MyException::operator=(const MyException &e) {
    if(this != &e){
        delete[] this->message;
        this->message = new char[strlen(e.message)+1];
        strcpy(this->message, e.message);
    }
    return *this;
}

MyException::~MyException() {
    delete[] this->message;
}
#endif //MAIN_CPP_MYEXCEPTION_H
