//
// Created by kyeou on 08/April/22.
//

// random change

#ifndef EXPENSE_TRACKER_COMPONENTS_H
#define EXPENSE_TRACKER_COMPONENTS_H

#endif // EXPENSE_TRACKER_COMPONENTS_H

#include "iostream"
#include "sstream"
#include "fstream"
#include "string"
#include "stdio.h"
#include "stdlib.h"
#include "json.hpp"

using json = nlohmann::json;

std::string months[] = {"January", "February", "March", "April", "May", "June",
                        "August", "September", "October", "November", "December"};

namespace ETglobal
{
    bool is_empty(std::ifstream &pFile)
    {
        return pFile.peek() == std::ifstream::traits_type::eof();
    }

    // things that needs to be global
    // A_O_T;
    int A_O_T, numOfBudgets;
    json transactionsJSON;
    std::ofstream transFileWrite;

    void Transaction_CLOSE()
    {
        // transFileWrite.close();
        transFileWrite.open("transactionsJSON.json");
        transFileWrite << std::setw(5) << transactionsJSON;
        transFileWrite.close();
        // free(date);
    }
}

using namespace ETglobal;

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

    Date getDate() { return *(this); }

    std::string getDateString()
    {
        // printf("Print Date Test: %s, %d, %d", months[date.getMonth()].substr(0, 3), date.getDay(),date.getYear());
        std::ostringstream os;
        // os << "Print Date Test: ";
        os << months[this->getMonth() - 1].substr(0, 3);
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
        this->date = date;
        this->amount = amount;
        this->recorded = false;
        // transFile.open("transactionsJSON.json", std::ios_base::out ); //| std::ios_base::app);
    }

    // need a boolean check to know when create new and and when to append
    // by default it can just be opened to append mode as open creates the file if doesnt exist, wont terminate if it does

    void setAll(std::string name, Date *date, float amount)
    {
        this->name = name;
        this->date->setDate(date->getMonth(), date->getDay(), date->getYear());
    }

    std::string getTransString()
    {
        std::ostringstream os;
        os << "Name: ";
        os << name;
        os << " | Date: ";
        os << this->date->getDateString();
        os << " | Amount: ";
        os << amount;

        return os.str();
    }

    void setAmount(float amount) { this->amount = amount; }

    void setName(std::string name) { this->name = name; }

    void setDate(Date *date) { this->date = date; }

    void setRecord(bool q) { this->recorded = q; }

    void setCorD(std::string s) { this->creditORdebit = (s.compare("Debit")) ? 0 : 1; }

    Date getDate() { return date->getDate(); }

    bool getCorD() { return this->creditORdebit; }

    std::string getName() { return this->name; }

    float getAmount() { return this->amount; }

    // write to the JSON variable
    void writeTrans()
    {
        transFileRead.open("transactionsJSON.json");
        if (!(is_empty(transFileRead)))
        {
            transFileRead.close();
            std::ifstream i("transactionsJSON.json");
            i >> transactionsJSON;
            i.close();
        }
        else
        {
            A_O_T = 0;
        }

    } // end of function

    void addTrans()
    {
        writeTrans();
        transFileWrite.open("transactionsJSON.json", std::ios_base::out);
        transactionsJSON[A_O_T]["Name: "] = this->name;
        transactionsJSON[A_O_T]["Date: "] = this->date->getDateString();
        transactionsJSON[A_O_T]["Amount: "] = this->amount;
        transactionsJSON[A_O_T]["ATTRIBUTE->RECORDED_BOOL: "] = this->recorded;
        A_O_T++;
        // transFileWrite.open("transactionsJSON.json");
        transFileWrite << std::setw(5) << transactionsJSON;
        transFileWrite.close();
    }

private:
    std::string name;
    Date *date;
    // ID int may not be used, but here just in case
    int id;
    // int A_O_T;
    float amount;
    bool recorded;
    // 1 for credit, 0 for debit
    bool creditORdebit;

    std::ifstream transFileRead;

}; // end class

// this class handles all user data, this created a user.json file that holds
// Income Budget Saving A_o_T Score
class USER
{
public:
    USER()
    {
        // file will need to be gathered through the access token granted from Google Drive API
        userRead.open("user.json");
        if (is_empty(userRead))
        {
            userRead.close();
            userWrite.open("user.json", std::ios_base::out);
            user = {
                {"Name", "FirstName LastName"},
                {"A_O_T", 0},
                {"Budgets", {0}},
                {"Income", 0},
                {"Scores", {}},
                {"SumDebits", 0}};
            // userWrite << std::setw(4) << user << std::endl;
            // userWrite.close();
        }
        else
        {
            // read file and gather data -> A_O_T
            userRead.close();
            std::ifstream i("user.json");
            i >> user;
            i.close();
            userWrite.open("user.json", std::ios_base::out);
            // need to read A_O_T value from JSON
            A_O_T = user["A_O_T"];
        }
    }
    // need a parse procedure for fields that are integer values

    void setUserValue(std::string s, int iValue, float dValue)
    {
        // when this function is called, if you want to set user["A_O_T"] -
        // call setUserValue("A_O_T", value, 0)
        // if you want set budget scores or sum debits
        //->setUserValue("A_O_T", 0, value)
        user[s] = (iValue != 0) ? iValue : dValue;
    }

    void addBudget(float amount)
    {
        int currAMT = user["Budgets"].size();
        // currAMT++;
        user["Budgets"][currAMT] = amount;
    }

    void recordDebits()
    {
        float temp = 0.0;
        int c = 0;
        // int itCount = 0;
        for (json::iterator it = transactionsJSON.begin(); it != transactionsJSON.end(); ++it)
        {

            if ((*it)["ATTRIBUTE->RECORDED_BOOL: "] == false)
            {
                // std::cout << (*it)["Amount: "] << std::endl;
                float as = (*it)["Amount: "];
                temp += as;
                (*it)["ATTRIBUTE->RECORDED_BOOL: "] = true;
                // itCount++;
            } // end if
        }
        user["SumDebits"].clear();
        user["SumDebits"] = temp;

        int iOS = user["Budgets"].size();
        float currBud = user["Budgets"][iOS - 1];
        if (((currBud - temp) / currBud) * 10 < 0)
        {
            user["Scores"][iOS - 1] = 0;
        }
        else
        {
            user["Scores"][iOS - 1] = ((currBud - temp) / currBud) * 10;
        }

user["Scores"][iOS - 1] = 



    }

    void USER_CLOSE()
    {
        /*
        A_O_T = 0;
        for (json::iterator it = transactionsJSON.begin(); it != transactionsJSON.end(); ++it)
        {
            A_O_T++;
        } */
        Transaction_CLOSE();
        setUserValue("A_O_T", A_O_T, 0);
        userWrite << std::setw(4) << user << std::endl;
        userWrite.close();
    }

    ~USER() {}

private:
    std::ifstream userRead;
    std::ofstream userWrite;
    json user;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
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
            //worksheet = WorkBook.workbook().worksheet("Sheet1");
            WorkBook.workbook().worksheet("Sheet1").cell("A1").value() = "Name";
            WorkBook.workbook().worksheet("Sheet1").cell("B1").value() = "Date";
            WorkBook.workbook().worksheet("Sheet1").cell("C1").value() = "Credit";
            WorkBook.workbook().worksheet("Sheet1").cell("D1").value() = "Debit";
            WorkBook.workbook().worksheet("Sheet1").cell("F1").value() = "Recording Bool";
            WorkBook.workbook().worksheet("Sheet1").cell("H1").value() = "Income";
            WorkBook.workbook().worksheet("Sheet1").cell("J1").value() = "Budget";
            WorkBook.workbook().worksheet("Sheet1").cell("L1").value() = "Savings";
            WorkBook.workbook().worksheet("Sheet1").cell("N1").value() = "A_O_T";
            WorkBook.workbook().worksheet("Sheet1").cell("P1").value() = "Score";

            // after this, the user must be prompted for monthly income and desired budget
        }
        //else
        //{
            // WorkBook.open("./UserData.xlsx");
            // = WorkBook.workbook().worksheet("Sheet1");
        //}
    } // end con struct

    void recordTransaction(Transaction *t, int i)
    {
        std::ostringstream cellString;
        char cs [] = {'A', 'B', 'Z', 'F'};
        std::string  ttr [4];
        ttr[0] = t->getName();
        ttr[1] = t->getDate().getDateString();
        cs[2] = (t->getCorD()) ? 'C' : 'D';
        ttr[2] = t->getAmount();
        ttr[3] = "0";
        for (int i = 0; i < 4; i++)
        {
            cellString << cs[i] << i;
            WorkBook.workbook().worksheet("Sheet1").cell(cellString.str()).value() = ttr[i];
        } // end for
    }     // end func

    ~SpreadSheet() {

        WorkBook.save();
    }


private:
    OpenXLSX::XLDocument WorkBook;
    //auto worksheet;
};
*/

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