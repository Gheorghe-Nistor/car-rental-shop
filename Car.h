//
// Created by George on 01.09.2022.
//
#ifndef MAIN_CPP_CAR_H
#define MAIN_CPP_CAR_H
class Car: public IOInterface{
protected:
    string model;
    int km;
    int year;
    bool available;
public:
    Car();
    Car(const string& model, int km, int year, bool available);
    Car(const Car& ob);
    Car& operator=(const Car& ob);

    virtual ~Car(){
        //cout << "An object of type CAR has been destroyed! \n";
    }

    Car& operator++();
    int operator+(const Car& ob) const;
    int operator-(const Car& ob) const;
    bool operator <=(const Car& ob) const;
    bool operator ==(const Car& ob);
    explicit operator int() const;
    explicit operator string() const;

    istream& write(istream& in);
    ostream& read(ostream& out) const;

    friend istream &operator>>(istream &in, Car &ob);
    friend ostream &operator<<(ostream &out, const Car &ob);

    virtual float price() = 0;
    int howOld() {return 2022-year;}

    string getModel();
    void setModel(const string &model);
    void setKm(int km);
    void setYear(int year);
    bool isAvailable() const;
    void setAvailable(bool available);
};
Car::Car(): model("N/A"), km(0), year(0), available(true){};
Car::Car(const string& model, int km, int year, bool available): model(model), km(km), year(year), available(available){};
Car::Car(const Car& ob): model(ob.model), km(ob.km), year(ob.year), available(ob.available){};
Car& Car::operator=(const Car& ob){
    if(this != &ob){
        this->model = ob.model;
        this->km = ob.km;
        this->year = ob.year;
        this->available = ob.available;
    }
    return *this;
}

istream& Car::write(istream& in){
    cout << "Model: ";
    in.ignore();
    getline(in, this->model);
    cout << "Km: ";
    in >> this->km;
    cout << "Year: ";
    in >> this->year;
    cout << "Available (0/1): ";
    in >> this->available;
    return in;
}
ostream& Car::read(ostream& out) const{
    out << "Model: " << this->model << '\n';
    out << "Km: " << this->km << '\n';
    out << "Year: " << this->year << '\n';
    out << "Available: " << (this->available ? "true":"false")<< '\n';
    return out;
}

istream &operator>>(istream &in, Car &ob){
    return ob.write(in);
}
ostream &operator<<(ostream &out, const Car &ob){
    return ob.read(out);
}

Car& Car::operator++(){
    this->km++;
    return *this;
}
int Car::operator+(const Car& ob) const{
    return this->km+ob.km;
}
int Car::operator-(const Car& ob) const{
    return this->km-ob.km;
}
bool Car::operator <=(const Car& ob) const{
    return this->km <= ob.km;
}
bool Car::operator ==(const Car& ob){
    return (this->year == ob.year) && (this->model == ob.model);
}
Car::operator int() const{
    return (int) this->year;
}
Car::operator string() const{
    return (string) this->model;
}

string Car::getModel() {
    return this->model;
}
void Car::setModel(const string &model) {
    this->model = model;
}
void Car::setKm(int km) {
    this->km = km;
}
void Car::setYear(int year) {
    this->year = year;
}
bool Car::isAvailable() const {
    return available;
}
void Car::setAvailable(bool available) {
    this->available = available;
}

#endif //MAIN_CPP_CAR_H