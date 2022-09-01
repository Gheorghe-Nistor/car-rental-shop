//
// Created by George on 01.09.2022.
//

#ifndef MAIN_CPP_INTERACTIVEMENU_H
#define MAIN_CPP_INTERACTIVEMENU_H
class InteractiveMenu{
    vector<Customer*> customersList;

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
    void menu();
};
InteractiveMenu* InteractiveMenu::instance = nullptr;

void InteractiveMenu::customer() {
    int k = 1;
    while(k) {
        cout << '\n';
        cout << "CUSTOMERS  \n";
        cout << "0 - back   \n";
        cout << "1 - create \n";
        cout << "2 - read   \n";
        cout << "3 - update \n";
        cout << "4 - delete \n";
        cout << "command: ";
        cin >> k;
        switch (k) {
            case 0:
                break;
            case 1: {
                auto* c = new Customer();
                cin >> *c;
                customersList.push_back(c);
                break;
            }
            case 2: {
                for(auto & it: customersList)
                    cout << *it << '\n';
                break;
            }
            case 3: {
                int id, index = 0;
                cout << "Customer ID: "; cin >> id;
                for(auto & it: customersList){
                    if(it->getID() == id)
                        break;
                    index++;
                }
                if(index == customersList.size()) {
                    cout << "Invalid ID! \n";
                    break;
                }
                int k1 = 1;
                cout << *customersList[index] << '\n';
                cout << "0 - back       \n";
                cout << "1 - First name \n";
                cout << "2 - Last name  \n";
                cout << "3 - Age        \n";
                cout << "4 - Occupation \n";
                cout << "command: ";
                cin >> k1;
                switch (k1) {
                    case 0:
                        break;
                    case 1:{
                        string f_name;
                        cout << "update: ";
                        cin >> f_name;
                        customersList[index]->setFName(f_name);
                        break;
                    }
                    case 2:{
                        string l_name;
                        cout << "update: ";
                        cin >> l_name;
                        customersList[index]->setLName(l_name);
                        break;
                    }
                    case 3:{
                        int age;
                        cout << "update: ";
                        cin >> age;
                        customersList[index]->setAge(age);
                        break;
                    }
                    case 4:{
                        char* occupation = new char[50];
                        cout << "update: ";
                        cin >> occupation;
                        customersList[index]->setOccupation(occupation);
                        delete[] occupation;
                        break;
                    }
                    default:
                        cout << "Enter a number between 0 and 4! \n";
                        break;
                }
                break;
            }
            case 4: {
                int id, index = 0;
                cout << "id: ";
                cin >> id;
                for(auto & it: customersList){
                    if(it->getID() == id) {
                        customersList.erase(customersList.begin() + index);
                        return;
                    }
                    index++;
                }
                break;
            }
            default:
                cout << "Enter a number between 0 and 4! \n";
                break;
        }
    }
}

void InteractiveMenu::menu(){
    int k = 1;
    while(k) {
        cout << '\n';
        cout << "0 - exit \n";
        cout << "1 - customers \n";
        cout << "command: ";
        cin >> k;
        switch (k) {
            case 0:
                cout << "See you soon! \n";
                break;
            case 1:
                this->customer();
                break;
            default:
                cout << "Enter a number between 0 and 1! \n";
                break;
        }
    }
}
#endif //MAIN_CPP_INTERACTIVEMENU_H
