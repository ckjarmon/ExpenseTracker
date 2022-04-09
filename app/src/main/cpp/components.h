//
// Created by kyeou on 08/April/22.
//

//Initial Cells
//Income Cell = I1
//Budget Cell = K1
//Savings Cell = M1
//A_O_T Cell = O1 =
//Score Cell = Q1 -> (K1 - SUM(D2:D)) / K1)



#ifndef EXPENSE_TRACKER_COMPONENTS_H
#define EXPENSE_TRACKER_COMPONENTS_H

#endif //EXPENSE_TRACKER_COMPONENTS_H

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <sstream>
#include <fstream>
#include <assert.h>

std::string months[]  = {"January", "February", "March", "April", "May", "June", \
"August", "September", "October", "November", "December"};

class Date {
public:

Date() {
    this->month = 0;
    this->day = 0;
    this->year = 0;
}

    Date(int month, int day, int year) {
        this->month = month;
        this->day = day;
        this->year = year;
    }


    __attribute__((unused)) std::string getMonthString(int i) {
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

    ~Date() {}
private:
    int month, day, year;
    std::string dateString;
};


class Transaction {
public:
    __attribute__((unused)) Transaction(std::string name, Date *date, float amount) {
        this->name = name;
        this->date = *date;
        this->amount = amount;
    }

    void setAll(std::string name, Date date, float amount) {
        this->name = name;
        this->date.setDate(date.getMonth(), date.getDay(), date.getYear());
    }

    std::string getTransString() {
        std::ostringstream os;
        os << "Name: ";
        os << name;
        os << " | Date: ";
        os << this->date.getDateString();
        os << " | Amount: ";
        os << amount;

        return os.str();
    }

    void setAmount(float amount) {
        this->amount = amount;
    }

    void setName (std::string name) {
        this->name = name;
    }

    void setDate(Date *date) {
        this->date = *date;
    }



~Transaction() {}
private:
    std::string name;
    Date date;
    float amount;


};//end class


class Database {

public:
    Database() {
        list = (Transaction*)malloc(count*sizeof(Transaction));
        count = 0;
    }

    __attribute__((unused)) void recordTrans(Transaction t) {
        count++;
        list = (Transaction*)realloc(list, count*sizeof(Transaction));
        list[count - 1] = t;
    }

    __attribute__((unused)) Transaction getTrans(int i) {
        return list[i];
    }

    bool compareTrans(Transaction t, Transaction y) {
        return (t.getTransString() == y.getTransString());
    }

private:
    Transaction *list;
    int count;
}; //end database class




class Budget {
public:
    Budget(int ID, float amount) {
        this->ID = ID;
        this->amount = amount;
    }

    Budget changeBudget(float newAmount) {
        return Budget(numOfBudgets, newAmount);
    }


private:
    int ID;
    float amount;
    int numOfBudgets;
};

class Report {};






__attribute__((unused)) void recordTransactionTest(Database d, Transaction t, Transaction y) {
    if (d.compareTrans(t, y)) {
        printf("Result: True\n\n"); } else {
        printf("Result: False\n\n");
    }
}//end func









//adding transaction to database will require a function call to setDate










/*
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
 */