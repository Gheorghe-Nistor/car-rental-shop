//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_INTERACTIVEMENU_H
#define MAIN_CPP_INTERACTIVEMENU_H

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define pressEnter   cout << "\n(press enter to continue)"; cin.ignore(); cin.ignore()
#define blueColor SetConsoleTextAttribute(hConsole, 3);
#define greenColor SetConsoleTextAttribute(hConsole, 10);
#define yellowColor SetConsoleTextAttribute(hConsole, 14);
#define whiteColor SetConsoleTextAttribute(hConsole, 15);
class InteractiveMenu{
    vector<Customer*> customersList;
    Warehouse<Car*> carsList;
    set<Customer*> activeCustomers;
    unordered_map<int, int> customerCar;
    list<string> rentalHistory;

    static InteractiveMenu* instance;
    InteractiveMenu() = default;
    InteractiveMenu(const InteractiveMenu& ob) = default;
    InteractiveMenu& operator=(const InteractiveMenu& ob) = default;
public:
    static InteractiveMenu* getInstance(){
        if(instance == nullptr)
            instance = new InteractiveMenu;
        return instance;
    }
    static void deleteInstance() {
        delete instance;
        instance = nullptr;
    }
    void customer();
    void car();
    void rentCar();
    void menu();
};
InteractiveMenu* InteractiveMenu::instance = nullptr;

void InteractiveMenu::customer() {
    int k = 1;
    while(k) {
        system("cls");
        blueColor;
        cout << "~> CUSTOMER MENU <~\n";
        yellowColor;
        cout << "0 - back   \n";
        cout << "1 - create \n";
        cout << "2 - read   \n";
        cout << "3 - update \n";
        cout << "4 - delete \n";
        whiteColor;
        cout << ">> Command: ";
        cin >> k;
        yellowColor;
        if(k && k <= 4)
            system("cls");
        switch (k) {
            case 0:
                break;
            case 1: {
                auto* ob = new Customer();
                whiteColor;
                cin >> *ob;
                yellowColor;
                customersList.push_back(ob);
                break;
            }
            case 2: {
                for(auto & it: customersList)
                    cout << *it << '\n';
                break;
            }
            case 3: {
                int id, index = 0;
                cout << ">> Customer ID: "; cin >> id;
                cout << '\n';
                for(auto & it: customersList){
                    if(it->getID() == id)
                        break;
                    index++;
                }
                if(index == customersList.size()) {
                    cout << "The customer with ID " << id << " was not found.\n";
                    break;
                }
                int k1 = 1;
                cout << *customersList[index] << '\n';
                greenColor;
                cout << "~> CUSTOMER UPDATE <~\n";
                yellowColor;
                cout << "0 - back       \n";
                cout << "1 - First name \n";
                cout << "2 - Last name  \n";
                cout << "3 - Age        \n";
                cout << "4 - Occupation \n";
                whiteColor;
                cout << ">> Command: ";
                cin >> k1;
                yellowColor;
                switch (k1) {
                    case 0:
                        break;
                    case 1:{
                        string f_name;
                        whiteColor;
                        cout << ">> Update first name: ";
                        cin >> f_name;
                        yellowColor;
                        customersList[index]->setFName(f_name);
                        break;
                    }
                    case 2:{
                        string l_name;
                        whiteColor;
                        cout << ">> Update last name: ";
                        cin >> l_name;
                        yellowColor;
                        customersList[index]->setLName(l_name);
                        break;
                    }
                    case 3:{
                        int age;
                        whiteColor;
                        cout << ">> Update age: ";
                        cin >> age;
                        yellowColor;
                        customersList[index]->setAge(age);
                        break;
                    }
                    case 4:{
                        char* occupation = new char[50];
                        whiteColor;
                        cout << ">> Update occupation: ";
                        cin >> occupation;
                        yellowColor;
                        customersList[index]->setOccupation(occupation);
                        delete[] occupation;
                        break;
                    }
                    default:
                        cout << "<< Enter a number between 0 and 4 >>\n";
                        break;
                }
                break;
            }
            case 4: {
                int id, index = 0;
                bool found = false;
                whiteColor;
                cout << ">> Customer ID: ";
                cin >> id;
                yellowColor;
                cout << '\n';
                for(auto & it: customersList){
                    if(it->getID() == id) {
                        customersList.erase(customersList.begin() + index);
                        cout << "The customer with ID " << id << " has been deleted.\n";
                        found = true;
                        break;
                    }
                    index++;
                }
                if(!found)
                    cout << "The customer with ID " << id << " was not found.\n";
                break;
            }
            default:
                cout << "<< Enter a number between 0 and 4 >> \n";
                break;
        }
        pressEnter;
    }
}
void InteractiveMenu::car(){
    int k = 1;
    while(k) {
        system("cls");
        blueColor;
        cout << "~> CAR MENU <~\n";
        yellowColor;
        cout << "0 - back   \n";
        cout << "1 - create \n";
        cout << "2 - read   \n";
        cout << "3 - update \n";
        cout << "4 - delete \n";
        whiteColor;
        cout << ">> Command: ";
        cin >> k;
        yellowColor;
        if(k && k <= 4)
            system("cls");
        switch (k) {
            case 0:
                break;
            case 1: {
                greenColor;
                cout << "~> CREATE A CAR <~\n";
                yellowColor;
                cout << "0 - back \n";
                cout << "1 - gasoline \n";
                cout << "2 - electric \n";
                cout << "3 - hybrid \n";
                auto* c = new Customer();
                whiteColor;
                int k1;
                cout << ">> Command: ";
                cin >> k1;
                if(k1 && k1 <= 3)
                    system("cls");
                switch (k1) {
                    case 0:
                        break;
                    case 1:{
                        Car* ob = new Gasoline();
                        cin >> *ob;
                        carsList.insert(ob);
                        break;
                    }
                    case 2:{
                        Car* ob = new Electric();
                        cin >> *ob;
                        carsList.insert(ob);
                        break;
                    }
                    case 3:{
                        Car* ob = new Hybrid();
                        cin >> *ob;
                        carsList.insert(ob);
                        break;
                    }
                    default: {
                        yellowColor;
                        cout << "\n<< Enter a number between 0 and 3 >>\n";
                        break;
                    }
                }
                yellowColor;
                break;
            }
            case 2: {
                cout << carsList;
                break;
            }
            case 3: {
                int id, index = 0;
                cout << ">> Car ID: "; cin >> id;
                cout << '\n';
                Car* ob = carsList.getCardById(id);
                if(ob == nullptr) {
                    cout << "The car with ID " << id << " was not found.\n";
                    break;
                }
                int k1 = 1;
                cout << *ob << '\n';
                greenColor;
                cout << "~> CAR UPDATE <~\n";
                yellowColor;
                cout << "0 - back   \n";
                cout << "1 - Model  \n";
                cout << "2 - Km     \n";
                cout << "3 - Year   \n";
                if(typeid(*ob) == typeid(Gasoline))
                    cout << "4 - Fuel type \n";
                else if(typeid(*ob) == typeid(Electric))
                    cout << "4 - Range \n";
                if(typeid(*ob) == typeid(Hybrid)) {
                    cout << "4 - Fuel type \n";
                    cout << "5 - Range     \n";
                }
                whiteColor;
                cout << ">> Command: ";
                cin >> k1;
                yellowColor;
                if(k1 <= 3) {
                    switch (k1) {
                        case 0:
                            break;
                        case 1: {
                            string model;
                            whiteColor;
                            cout << ">> Update model: ";
                            cin.ignore();
                            getline(cin, model);
                            yellowColor;
                            ob->setModel(model);
                            break;
                        }
                        case 2: {
                            int km;
                            whiteColor;
                            cout << ">> Update km: ";
                            cin >> km;
                            yellowColor;
                            ob->setKm(km);
                            break;
                        }
                        case 3: {
                            int year;
                            whiteColor;
                            cout << ">> Update year: ";
                            cin >> year;
                            yellowColor;
                            ob->setYear(year);
                            break;
                        }
                        default:
                            cout << "<< Enter a number between 0 and 4 >>\n";
                            break;
                    }
                }
                else {
                    try{
                        auto* dc = dynamic_cast<Hybrid*>(ob);
                        if(dc == nullptr)
                            throw bad_cast();
                        if(k1 == 4){
                            string fuel_type;
                            whiteColor;
                            cout << ">> Update fuel type: ";
                            cin >> fuel_type;
                            yellowColor;
                            dc->setFuelType(fuel_type);
                        }
                        else if(k1 == 5){
                            double range;
                            whiteColor;
                            cout << ">> Update range: ";
                            cin >> range;
                            yellowColor;
                            dc->setRange(range);
                        }
                        else
                            cout << "<< Enter a number between 0 and 5 >> \n";
                    }
                    catch(const bad_cast& e){
                        try{
                            auto* dc = dynamic_cast<Electric*>(ob);
                            if(dc == nullptr)
                                throw bad_cast();
                            if(k1 == 4){
                                double range;
                                whiteColor;
                                cout << ">> Update range: ";
                                cin >> range;
                                yellowColor;
                                dc->setRange(range);
                            }
                            else
                                cout << "<< Enter a number between 0 and 4 >> \n";
                        }
                        catch(const bad_cast& e){
                            auto* dc = dynamic_cast<Gasoline*>(ob);
                            if(k1 == 4){
                                string fuel_type;
                                whiteColor;
                                cout << ">> Update fuel type: ";
                                cin >> fuel_type;
                                yellowColor;
                                dc->setFuelType(fuel_type);
                            }
                            else
                                cout << "<< Enter a number between 0 and 4 >> \n";
                        }
                    }
                }
                break;
            }
            case 4: {
                int id;
                whiteColor;
                cout << ">> Car ID: ";
                cin >> id;
                yellowColor;
                cout << '\n';
                Car* ob = carsList.getCardById(id);
                if(ob != nullptr){
                    cout << *ob;
                    carsList.remove(id);
                    cout << "\nThe car with ID " << id << " has been deleted. \n";
                }
                else
                    cout << "The car with ID " << id << " was not found.\n";
                break;
            }
            default:
                cout << "<< Enter a number between 0 and 4 >> \n";
                break;
        }
        pressEnter;
    }
}
void InteractiveMenu::rentCar(){
    int k = 1;
    while(k) {
        system("cls");
        blueColor;
        cout << "~> RENT CAR MENU <~\n";
        yellowColor;
        cout << "0 - back               \n";
        cout << "1 - available cars     \n";
        cout << "2 - unavailable cars   \n";
        cout << "3 - rent car           \n";
        cout << "4 - active customers   \n";
        cout << "5 - customer & car     \n";
        cout << "6 - end the car rental \n";
        cout << "7 - rental history     \n";
        whiteColor;
        cout << ">> Command: ";
        cin >> k;
        if(k > 0 && k <= 7)
            system("cls");
        yellowColor;
        switch (k) {
            case 0:{
                break;
            }
            case 1:{
                carsList.availableCars();
                break;
            }
            case 2:{
                carsList.unavailableCars();
                break;
            }
            case 3:{
                string currentRecord = "";
                int customerID, carID, index = 0;
                whiteColor;
                cout << ">> Customer ID: ";
                cin >> customerID;
                yellowColor;
                cout << '\n';
                Customer* customer;
                bool is_in;
                for(auto & it: customersList){
                    if(it->getID() == customerID) {
                        customer = it;
                        is_in = activeCustomers.find(customer) != activeCustomers.end();
                        cout << *it << '\n';
                        currentRecord = it->getFName() + ' ' + it->getLName() + '(' + to_string(it->getID()) + ") - ";
                        break;
                    }
                    index++;
                }
                if(is_in){
                    cout << "\nThe customer with ID " << customerID << " already has a rented car.\n";
                    break;
                }
                if(index == customersList.size()) {
                    cout << "The customer with ID " << customerID << " was not found.\n";
                    break;
                }
                whiteColor;
                cout << ">> Car ID: ";
                cin >> carID;
                yellowColor;
                cout << '\n';
                Car* ob = carsList.getCardById(carID);
                if(ob != nullptr){
                    cout << *ob << '\n';
                    if(!ob->isAvailable()){
                        cout << "\nThe car with ID " << carID << " is not available at the moment.\n";
                        break;
                    }
                    ob->setAvailable(false);
                    currentRecord += ob->getModel() + '(' + to_string(carID) + ')';
                    rentalHistory.push_back(currentRecord);
                    activeCustomers.insert(customer);
                    customerCar[customerID] = carID;
                    cout << "\nThe car with ID " << carID << " was given for rent to the customer with ID " << customerID << ".\n";
                    cout << "Price: " << ob->price() << " e \n";
                }
                else
                    cout << "The car with ID " << carID << " was not found.\n";
                break;
            }
            case 4:{
                for(auto & it: activeCustomers)
                    cout << *it << '\n';
                break;
            }
            case 5:{
                int index = 0;
                for(auto & it: customerCar){
                    cout << "ID: " << index             << '\n';
                    cout << "Customer ID: " << it.first << '\n';
                    cout << "CAR ID: " << it.second     << '\n';
                    cout << '\n';
                    index++;
                }
                break;
            }
            case 6:{
                int index, customerID, carID;
                whiteColor;
                cout << ">> Customer & Car ID: ";
                cin >> index;
                yellowColor;
                if(index >= 0 and index < customerCar.size()){
                    auto it = customerCar.begin();
                    std::advance(it, index);
                    customerID = it->first;
                    carID = it->second;
                    customerCar.erase(it);

                    for(auto & it: customersList)
                        if(it->getID() == customerID) {
                            activeCustomers.erase(it);
                            break;
                        }
                    carsList.getCardById(carID)->setAvailable(true);
                    cout << "\nDone! \n";
                }
                else
                    cout << "\nThe entered ID does not correspond to any car rental.\n";
                break;
            }
            case 7:{
                for(auto & it: rentalHistory)
                    cout << it << '\n';
                break;
            }
            default:{
                cout << "\n<< Enter a number between 0 and 7 >\n";
                break;
            }
        }
        pressEnter;
    }
}

void InteractiveMenu::menu(){
    int k = 1;
    Customer* customer1 = new Customer("Gheorghe", "Nistor", 20, "student");
    Car* car1 = new Electric("Eletric Car", 0, 2022, 1, 500);
    customersList.push_back(customer1);
    carsList.insert(car1);

    while(k) {
        system("cls");
        blueColor;
        cout << "~> MAIN MENU <~\n";
        yellowColor;
        cout << "0 - exit \n";
        cout << "1 - customers  [CRUD] \n";
        cout << "2 - cars       [CRUD] \n";
        cout << "3 - rent car          \n";
        whiteColor;
        cout << ">> Command: ";
        cin >> k;
        yellowColor;
        switch (k) {
            case 0: {
                cout << "\nSee you soon! \n";
                pressEnter;
                break;
            }
            case 1: {
                this->customer();
                break;
            }
            case 2: {
                this->car();
                break;
            }
            case 3:{
                this->rentCar();
                break;
            }
            default: {
                cout << "\n<< Enter a number between 0 and 3 >>\n";
                pressEnter;
                break;
            }
        }
    }
}
#endif //MAIN_CPP_INTERACTIVEMENU_H
