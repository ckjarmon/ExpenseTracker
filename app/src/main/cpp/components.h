//
// Created by kyeou on 08/April/22.
//

// Initial Cells
// Income Cell = I1
// Budget Cell = K1
// Savings Cell = M1
// A_O_T Cell = O1 =
// Score Cell = Q1 -> (K1 - SUM(D2:D)) / K1)

// random change

#ifndef EXPENSE_TRACKER_COMPOENTS_H
#define EXPENSE_TRACKER_COMPONENTS_H

#endif // EXPENSE_TRACKER_COMPONENTS_H

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <sstream>
#include <OpenXLSX.hpp>

std::string months[] = {"January", "February", "March", "April", "May", "June",
                        "August", "September", "October", "November", "December"};

class Date
{
public:
    Date()
    {
        this->month = 0;
        this->day = 0;
        this->year = 0;
    }

    Date(int month, int day, int year)
    {
        this->month = month;
        this->day = day;
        this->year = year;
    }

    __attribute__((unused)) std::string getMonthString(int i)
    {
        return months[i - 1];
    }

    void setDate(int month, int day, int year)
    {
        this->month = month;
        this->day = day;
        this->year = year;
    }

    int getMonth() { return this->month; }
    int getDay() { return this->day; }
    int getYear() { return this->year; }

    Date getDate() { return this; }

    std::string getDateString()
    {
        // printf("Print Date Test: %s, %d, %d", months[date.getMonth()].substr(0, 3), date.getDay(),date.getYear());
        std::ostringstream os;
        // os << "Print Date Test: ";
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

class Transaction
{
public:
    __attribute__((unused)) Transaction(std::string name, Date *date, float amount)
    {
        this->name = name;
        this->date = *date;
        this->amount = amount;
    }

    void setAll(std::string name, Date date, float amount)
    {
        this->name = name;
        this->date.setDate(date.getMonth(), date.getDay(), date.getYear());
    }

    std::string getTransString()
    {
        std::ostringstream os;
        os << "Name: ";
        os << name;
        os << " | Date: ";
        os << this->date.getDateString();
        os << " | Amount: ";
        os << amount;

        return os.str();
    }

    void setAmount(float amount)
    {
        this->amount = amount;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    void setDate(Date *date)
    {
        this->date = *date;
    }

    void setRecord(bool q)
    {
        this->recorded = q;
    }

    void setCorD(std::string s)
    {
        this->creditORdebit = (s.compare("Debit")) ? 0 : 1;
    }

    Date getDate() { return date.getDate(); }

    bool getCorD() { return this->creditORdebit; }

    std::string getName() { return this->name; }
    float getAmount() { return this->amount; }

    ~Transaction()
    {
        free(date);
    }

private:
    std::string name;
    Date date;
    float amount;
    bool recorded;
    // 1 for credit, 0 for debit
    bool creditORdebit;

}; // end class

class Database
{

public:
    Database(SpreadSheet)
    {
        list = (Transaction *)malloc(count * sizeof(Transaction));
        count = 0;
    }

    __attribute__((unused)) void recordTrans(Transaction t)
    {
        A_O_T++;
        list = (Transaction *)realloc(list, count * sizeof(Transaction));
        list[count - 1] = t;
    }

    __attribute__((unused)) Transaction getTrans(int i)
    {
        return list[i];
    }

    bool compareTrans(Transaction t, Transaction y)
    {
        return (t.getTransString() == y.getTransString());
    }

private:
    Transaction *list;
    int A_O_T;
}; // end database class

class Budget
{
public:
    Budget(int ID, float amount)
    {
        this->ID = ID;
        this->amount = amount;
    }

    Budget changeBudget(float newAmount)
    {
        return Budget(numOfBudgets, newAmount);
    }

private:
    int ID;
    float amount;
    int numOfBudgets;
};

// class to manage spreadsheet
// Name Date Credit Debt   Recorded Bool
// A1    B1   C1      D1       F1

// Income Budget Saving A_o_T Score
// H        J       L     N     P
class SpreadSheet
{
public:
    SpreadSheet(bool con)
    {
        WorkBook.open("./UserData.xlsx");
        con = (WorkBook) ? 0 : 1;
        if (con == 0)
        {
            WorkBook.create("./UserData.xlsx");
            worksheet = WorkBook.workbook().worksheet("Sheet1");
            worksheet.cell("A1").value() = "Name";
            worksheet.cell("B1").value() = "Date";
            worksheet.cell("C1").value() = "Credit";
            worksheet.cell("D1").value() = "Debit";
            worksheet.cell("F1").value() = "Recording Bool";
            worksheet.cell("H1").value() = "Income";
            worksheet.cell("J1").value() = "Budget";
            worksheet.cell("L1").value() = "Savings";
            worksheet.cell("N1").value() = "A_O_T";
            worksheet.cell("P1").value() = "Score";

            // after this, the user must be prompted for monthly income and desired budget
        }
        else
        {
            // WorkBook.open("./UserData.xlsx");
            worksheet = WorkBook.workbook().worksheet("Sheet1");
        }
    } // end con struct

    void recordTransaction(Transaction *t, int i)
    {
        std::ostringstream cellString;
        char[] cs = {'A', 'B', 'Z', 'F'};
        std::string[4] ttr;
        ttr[0] = t->getName();
        ttr[1] = t->getDate();
        cs[2] = (t->getCorD()) ? 'C' : 'D';
        ttr[2] = t->getAmount();
        ttr[3] = "0";
        for (int i = 0; i < 4; i++)
        {
            cellString << cs[i] << i;
            worksheet.cell(cellString.str()).value() = ttr[i];
        } // end for
    }     // end func

private:
    XLDocument WorkBook;
    auto worksheet;
};

// adding transaction to database will require a function call to setDate

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