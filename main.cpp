#include <iostream>
#include <windows.h>
#include <exception>
#include <typeinfo>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <unordered_map>

using namespace std;

#include "IOInterface.h"
#include "MyException.h"
#include "Customer.h"
#include "Car.h"                // base class
#include "Electric.h"           // derived class 1
#include "Gasoline.h"           // derived class 2
#include "Hybrid.h"             // diamond class
#include "Warehouse.h"          // template class
#include "InteractiveMenu.h"    // singleton class

int main(){
    InteractiveMenu *m = InteractiveMenu::getInstance();
    m->menu();
    InteractiveMenu::deleteInstance();
    return 0;
}