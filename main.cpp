#include <iostream>
#include <exception>
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
#include "Car.h"
#include "Electric.h"
#include "Gasoline.h"
#include "Hybrid.h"
#include "Warehouse.h"
#include "RentalShop.h"
#include "InteractiveMenu.h"

int main() {
    InteractiveMenu *m = InteractiveMenu::getInstance();
    m->menu();
    InteractiveMenu::deleteInstance();
    return 0;
}