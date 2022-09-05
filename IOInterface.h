//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_IOINTERFACE_H
#define MAIN_CPP_IOINTERFACE_H
class IOInterface{
public:
    virtual std::istream& write(std::istream& in) = 0;
    virtual std::ostream& read(std::ostream& out) const = 0;
};
#endif //MAIN_CPP_IOINTERFACE_H
