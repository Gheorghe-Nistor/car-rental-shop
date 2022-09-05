//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_GASOLINE_H
#define MAIN_CPP_GASOLINE_H
class Gasoline: public virtual Car{
protected:
    string fuel_type;
public:
    Gasoline();
    Gasoline(const string& model, int km, int year, bool available, const string& fuel_type);
    Gasoline(const Gasoline& ob);
    Gasoline& operator=(const Gasoline& ob);

    istream& write(istream& in);
    ostream& read(ostream& out) const;

    friend istream& operator>>(istream& in, Gasoline& ob);
    friend ostream& operator<<(ostream& out, const Gasoline& ob);

    void setFuelType(const string& fuel_type);
    float price() {return 100;}
};

Gasoline::Gasoline():Car(), fuel_type("N/A"){};
Gasoline::Gasoline(const string& model, int km, int year, bool available, const string& fuel_type):Car(model, km, year, available), fuel_type(fuel_type){};
Gasoline::Gasoline(const Gasoline& ob):Car(ob), fuel_type(ob.fuel_type){};
Gasoline& Gasoline::operator=(const Gasoline& ob){
    if(this != &ob){
        Car::operator=(ob);
        this->fuel_type = ob.fuel_type;
    }
    return *this;
}

istream& Gasoline::write(istream& in){
    Car::write(in);
    cout << "Fuel type: "; in >> this->fuel_type;
    return in;
}
ostream& Gasoline::read(ostream& out) const{
    Car::read(out);
    out << "Fuel type: " << this->fuel_type << '\n';
    return out;
}

istream& operator>>(istream& in, Gasoline& ob){
    return ob.write(in);
}
ostream& operator<<(ostream& out, const Gasoline& ob){
    return ob.read(out);
}

void Gasoline::setFuelType(const string& fuel_type){
    this->fuel_type = fuel_type;
}
#endif //MAIN_CPP_GASOLINE_H
