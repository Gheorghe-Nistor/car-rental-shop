//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_WAREHOUSE_H
#define MAIN_CPP_WAREHOUSE_H
template <class T>
class Warehouse{
    T* cars;
    int size;
    int max_capacity;
public:
    Warehouse();
    Warehouse(int size, int max_capacity);
    Warehouse(T* cars, int size, int max_capacity);
    Warehouse(const Warehouse& ob);
    Warehouse& operator=(const Warehouse& ob);

    template<typename Tptr>
    friend ostream& operator<<(ostream& out, const Warehouse<Tptr>& ob);

    void insert(T& ob);
    T getCardById(int index) const;
    void remove(int index);
    void availableCars();
    void unavailableCars();
};

template <class T>
Warehouse<T>::Warehouse(){
    this->cars = new T[20];
    this->size = 0;
    this->max_capacity = 20;
}

template <class T>
Warehouse<T>::Warehouse(int size, int max_capacity){
    this->size = size;
    this->max_capacity = max_capacity;
    this->cars = new T[max_capacity];
}

template <class T>
Warehouse<T>::Warehouse(T* cars, int size, int max_capacity){
    this->cars = cars;
    this->size = size;
    this->max_capacity = max_capacity;
}

template <class T>
Warehouse<T>::Warehouse(const Warehouse& ob){
    this->cars = ob.cars;
    this->size = ob.size;
    this->max_capacity = ob.max_capacity;
}

template <class T>
Warehouse<T>& Warehouse<T>::operator=(const Warehouse& ob){
    if(this != &ob){
        delete[] cars;
        this->cars = ob.cars;
        this->size = ob.size;
        this->max_capacity = ob.max_capacity;
    }
    return *this;
}

/*template <class T>
const T& Warehouse<T>::operator[](const int index) {
    if (index >= 0 and index < this->size) {
        return this->cars[index];
    }
    return nullptr;
}*/

template <class Tptr>
ostream& operator<<(ostream& out, const Warehouse<Tptr>& ob){
    for(int i = 0; i < ob.size; i++) {
        cout << "ID: " << i << '\n';
        cout << *ob.cars[i] << '\n';
    }
    return out;
}

template <class T>
void Warehouse<T>::insert(T& ob){
    if(this->size == this->max_capacity)
        cout << "You have no more space to add a vehicle!";
    else
        this->cars[this->size++] = ob;
}

template <class T>
T Warehouse<T>::getCardById(int index) const{
    if(index >= 0 and index < this->size)
        return this->cars[index];
    return nullptr;
}

template<class T>
void Warehouse<T>::remove(const int index){
    if(index >= 0 and index < this->size){
        delete this->cars[index];
        this->size--;
        int i;
        for(i = index; i < this->size; i++){
            cars[i] = cars[i+1];
        }
    }
}
template<class T>
void Warehouse<T>::availableCars(){
    for(int i = 0; i < this->size; i++)
        if(this->cars[i]->isAvailable()) {
            cout << "ID: " << i << '\n';
            cout << *this->cars[i] << '\n';
        }
}
template<class T>
void Warehouse<T>::unavailableCars(){
    for(int i = 0; i < this->size; i++)
        if(!this->cars[i]->isAvailable()){
            cout << "ID: " << i << '\n';
            cout << *this->cars[i] << '\n';
        }
}

#endif //MAIN_CPP_WAREHOUSE_H
