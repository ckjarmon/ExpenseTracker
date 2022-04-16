#include "components.hpp"

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}


int main() {
    Transaction test1("Ralphs 1", new Date(1, 1, 2000), 12.34);
    std::cout << test1.getTransString() << "\n";
    test1.addTrans();

    Transaction test2("Ralphs 2", new Date(1, 1, 2000), 12.34);
    std::cout << test2.getTransString() << "\n";
    test2.addTrans();

    Transaction test3("Ralphs 3", new Date(1, 1, 2000), 12.34);
    std::cout << test3.getTransString() << "\n";
    test3.addTrans();

/*
for (json::iterator it = test3.getJSON().begin(); it != test3.getJSON().end(); ++it) {
  std::cout << (*it)["Name"] << '\n';
} */








}