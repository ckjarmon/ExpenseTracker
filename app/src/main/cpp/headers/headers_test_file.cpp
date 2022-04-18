#include "components.hpp"



int main() {


std::fstream file;
file.open("transactionsJSON.json", std::ios_base::out);
file << "";
file.close();
file.open("user.json", std::ios_base::out);
file << "";
file.close();


USER *user = new USER();

  
    Transaction test1("Ralphs 1", new Date(1, 1, 2000), 12.34);
    std::cout << test1.getTransString() << "\n";
    test1.addTrans();

    Transaction test2("Ralphs 2", new Date(1, 1, 2000), 12.34);
    std::cout << test2.getTransString() << "\n";
    test2.addTrans();

    Transaction test3("Ralphs 3", new Date(1, 1, 2000), 12.34);
    std::cout << test3.getTransString() << "\n";
    test3.addTrans();

    Transaction test4("Ralphs 4", new Date(2, 2, 2000), 56.78);
    std::cout << test4.getTransString() << "\n";
    test4.addTrans();

    Transaction test5("Ralphs 5", new Date(2, 2, 2000), 56.78);
    std::cout << test5.getTransString() << "\n";
    test5.addTrans();

    Transaction test6("Ralphs 6", new Date(2, 2, 2000), 56.78);
    std::cout << test6.getTransString() << "\n";
    test6.addTrans();

    
    Transaction test7("Ralphs 7", new Date(2, 2, 2000), 200.00);
    std::cout << test7.getTransString() << "\n";
    test7.addTrans();

user->addBudget(632.32);
user->addBudget(812.65);
user->addBudget(3214.32);
user->recordDebits();

/*
for (json::iterator it = test3.getJSON().begin(); it != test3.getJSON().end(); ++it) {
  std::cout << (*it)["Name"] << '\n';
} */




user->USER_CLOSE();



}