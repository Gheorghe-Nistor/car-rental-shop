//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_HYBRID_H
#define MAIN_CPP_HYBRID_H
class Hybrid: public virtual Electric, public virtual Gasoline{
public:
    Hybrid();
    Hybrid(const string& model, int km, int year, bool available, const string& fuel_type, double range);
    Hybrid(const Hybrid& ob);
    Hybrid& operator=(const Hybrid& ob);

    istream& write(istream& in);
    ostream& read(ostream& out) const;

    friend istream& operator>>(istream& in, Electric& ob);
    friend ostream& operator<<(ostream& out, const Electric& ob);

    float price() {return 125;} // formula random
};
Hybrid::Hybrid():Car(), Gasoline(), Electric(){}
Hybrid::Hybrid(const string& model, int km, int year, bool available, const string& fuel_type, double range):
    Car(model, km, year, available),
    Gasoline(model, km, year, available, fuel_type),
    Electric(model, km, year, available, range){}
Hybrid::Hybrid(const Hybrid& ob):Car(ob), Gasoline(ob), Electric(ob){}
Hybrid& Hybrid::operator=(const Hybrid& ob){
    if(this != &ob){
        Gasoline::operator=(ob);
        Electric::operator=(ob);
    }
    return *this;
}

istream& Hybrid::write(istream& in){
    Gasoline::write(in);
    Electric::write(in);
    return in;
}
ostream& Hybrid::read(ostream& out) const{
    Gasoline::read(out);
    Electric::read(out);
    return out;
}

istream& operator>>(istream& in, Hybrid& ob){
    return ob.write(in);
}
ostream& operator<<(ostream& out, const Hybrid& ob){
    return ob.read(out);
}
#endif //MAIN_CPP_HYBRID_H
