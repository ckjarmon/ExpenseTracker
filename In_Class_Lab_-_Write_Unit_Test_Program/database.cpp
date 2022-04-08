#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <sstream>
#include <fstream>
#include <assert.h>

std::string months[]  = {"January", "February", "March", "April", "May", "June", "August", "September", "October", "November", "December"}; 

class Date {
public:

Date();
Date(int month, int day, int year) {
    this->month = month;
    this->day = day;
    this->year = year;
}


std::string getMonthString(int i) {
    return months[i-1];
}

void setDate(int month, int day, int year) {
    this->month = month;
    this->day = day;
    this->year = year;
}

int getMonth() {return month;}
int getDay() {return day;}
int getYear() {return year;}

std::string getDateString() {
    // printf("Print Date Test: %s, %d, %d", months[date.getMonth()].substr(0, 3), date.getDay(),date.getYear());
     std::ostringstream os;
    //os << "Print Date Test: ";
    os << months[this->getMonth()].substr(0, 3);
    os << " ";
    os << this->getDay();
    os << ", ";
    os << this->getYear();
return os.str();
}

~Date();
private:
    int month, day, year;
    std::string dateString;
};


class Transaction {
public:
    Transaction(std::string name, Date *date, float amount) {
        this->name = name;
        this->date = date;
        this->amount = amount;
    }

void setAll(std::string name, Date date, float amount) {
this->name = name;
this->date->setDate(date.getMonth(), date.getDay(), date.getYear());
}

std::string getTransString() {
    std::ostringstream os;
    os << "Name: ";
    os << name;
    os << " | Date: ";
    os << this->date->getDateString();
    os << " | Amount: ";
    os << amount;

return os.str();
}

void setAmount(float a) {
amount = a;
}

//~Transaction();
private:
    std::string name;
    Date *date;
    float amount;


};//end class


class Database {

public: 
Database() {
    list =(Transaction*)malloc(count*sizeof(Transaction)) ;
    count = 0;
}

void recordTrans(Transaction t) {
    count++;
    list = (Transaction*)realloc(list, count*sizeof(Transaction));
    list[count - 1] = t;
}

Transaction getTrans(int i) {
return list[i];
}

bool compareTrans(Transaction t, Transaction y) {
    return (t.getTransString() == y.getTransString());
}

private:
Transaction *list;
int count;
}; //end database class


void recordTransactionTest(Database d, Transaction t, Transaction y) {
    if (d.compareTrans(t, y) == true) {
printf("Result: True\n\n"); } else {
    printf("Result: False\n\n");
}
}//end func


int main() {
    
//printf("\n\nValid Case Check: Date is Valid, Transaction is Valid\n");
Date *date = new Date(1, 1, 2000);
Transaction trans = Transaction("Test Transaction", date, 12.34);
Database database;
database.recordTrans(trans);
//printf("%s" , database.getTrans(0).getTransString().c_str());
//printf("Date String Test: \n%s\n-------\n", date->getDateString().c_str());
printf("Transaction String: \n%s\n\n", trans.getTransString().c_str());

printf("recordTransaction() Tests\n");
printf("-------\nTest: First Recorded Transaction = Test Transaction\nExpected Result: True\n\n");
printf("Transaction String: \n%s\n\n", trans.getTransString().c_str());
printf("Recorded Transaction: \n%s\n\n", database.getTrans(0).getTransString().c_str());
recordTransactionTest(database, trans, database.getTrans(0));

printf("-------\nTest: Recorded Transaction Has Different Dollar Amount:\nExpected Result: False\n\n"); 
trans.setAmount(32.65);
printf("Transaction String: \n%s\n\n", trans.getTransString().c_str());
printf("Recorded Transaction: \n%s\n\n", database.getTrans(0).getTransString().c_str());
recordTransactionTest(database, trans, database.getTrans(0));




}