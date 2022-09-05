//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_ELECTRIC_H
#define MAIN_CPP_ELECTRIC_H
class Electric: public virtual Car{
protected:
    double range;
public:
    Electric();
    Electric(const string& model, int km, int year, bool available, double range);
    Electric(const Electric& ob);
    Electric& operator=(const Electric& ob);

    istream& write(istream& in);
    ostream& read(ostream& out) const;

    friend istream& operator>>(istream& in, Electric& ob);
    friend ostream& operator<<(ostream& out, const Electric& ob);

    float price(){return 150;}
    double numberOfBatteryRecharges(int km){
        return km/range;
    }
    void setRange(double range);
};

Electric::Electric():Car(), range(0){};
Electric::Electric(const string& model, int km, int year, bool available, double range):Car(model, km, year, available), range(range){};
Electric::Electric(const Electric& ob):Car(ob), range(ob.range){};
Electric& Electric::operator=(const Electric& ob){
    if(this != &ob){
        Car::operator=(ob);
        this->range = ob.range;
    }
    return *this;
}

istream& Electric::write(istream& in){
    if (typeid(*this) == typeid(Electric))
        Car::write(in);
    cout << "Range: "; in >> this->range;
    return in;
}
ostream& Electric::read(ostream& out) const{
    if (typeid(*this) == typeid(Electric))
        Car::read(out);
    out << "Range: " << this->range << " km \n";
    return out;
}

istream& operator>>(istream& in, Electric& ob){
    return ob.write(in);
}
ostream& operator<<(ostream& out, const Electric& ob){
    return ob.read(out);
}

void Electric::setRange(double range){
    this->range = range;
}
#endif //MAIN_CPP_ELECTRIC_H
