//
// Created by kyeou on 08/April/22.
//

// the whole JNI scheme will work to create the json values and returns strings back to java to read them into the files

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

std::string months[] = {"January", "February", "March", "April", "May", "June", "July",
                        "August", "September", "October", "November", "December"};

namespace GLOBAL_VARS
{
    json TRANSACTIONS_JSON, USER_JSON, RANKS_JSON, TOP_JSON;
    int A_O_T, A_O_B, A_O_R = 0, T_O_A_T = 0;
    float global_debit_bal;
    int MONTH_COUNT[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::string reportString = "";
    std::string recordDebits()
    {
        global_debit_bal = 0.0;
        int c = 0;
        // TRANSACTIONS_JSON = json::parse(trans_parm);
        // USER_JSON = json::parse(user_parm);
        for (json::iterator it = TRANSACTIONS_JSON.begin(); it != TRANSACTIONS_JSON.end(); ++it)
        {
            (*it)["ATTRIBUTE->RECORDED_BOOL"] = false;
        }
        for (json::iterator it = TRANSACTIONS_JSON.begin(); it != TRANSACTIONS_JSON.end(); ++it)
        {
            if ((*it)["ATTRIBUTE->RECORDED_BOOL"] == false)
            {
                float as = (*it)["Amount"];
                global_debit_bal += as;
                (*it)["ATTRIBUTE->RECORDED_BOOL"] = true;
                // itCount++;
            } // end if
        }     // end for

        USER_JSON["SumDebits"].clear();
        USER_JSON["SumDebits"] = global_debit_bal;

        A_O_B = USER_JSON["Budgets"].size();

        for (int i = 0; i < A_O_B; i++)
        {
            float currBud = USER_JSON["Budgets"][i];
            USER_JSON["Scores"][i] = (((currBud - global_debit_bal) / currBud) * 10 < 0) ? 0 : ((currBud - global_debit_bal) / currBud) * 10;
        }

        return TRANSACTIONS_JSON.dump();

    } // end recordDebits

    float correctBalance(float b)
    {
        recordDebits();
        return (b - global_debit_bal);
    }

    void establishRanks(int month1, int year1)
    {
        std::ostringstream os;
        os << months[month1] << "/" << year1;
        reportString = os.str();
        RANKS_JSON.clear();
        A_O_R = 0;
        float static_max = std::numeric_limits<float>::max();
        float curr_max = std::numeric_limits<float>::min();

        int ranked = 0;
        int b_s = (USER_JSON["MONTH_COUNTER"][month1 - 1]);
        int max_rankings = ( b_s > 20) ? 20 : b_s;
        while (ranked < max_rankings)
        {
            curr_max = std::numeric_limits<float>::min();
            for (json::iterator it = TRANSACTIONS_JSON.begin(); it != TRANSACTIONS_JSON.end(); ++it)
            {

                if ((*it)["Amount"] >= curr_max && (*it)["Amount"] < static_max && ((*it)["Date->Month"] == month1) && ((*it)["Date->Year"] == year1) && (*it)["Ranked"] != true)
                {
                    RANKS_JSON[A_O_R] = (*it);
                    curr_max = (*it)["Amount"];
                }
            }
            static_max = curr_max;
            RANKS_JSON[A_O_R]["Ranked"] = true;
            A_O_R = RANKS_JSON.size();
            ranked++;
        } // end while
        /*
        for (json::iterator it = RANKS_JSON.begin(); it != RANKS_JSON.end(); ++it)
        {
            std::cout << (*it)["THIS->STRING: "] << std::endl;
        } */
    }

    void establishTop()
    {
        TOP_JSON.clear();
        T_O_A_T = 0;
        float static_max = std::numeric_limits<float>::max();
        float curr_max = std::numeric_limits<float>::min();

        int ranked = 0;
        // int max_rankings = USER_JSON["MONTH_COUNTER"][month1 - 1];

        int max_rankings = (TRANSACTIONS_JSON.size() < 10) ? TRANSACTIONS_JSON.size() : 10;
        // std::cout << "TOP ALL TIME AMOUNT " << max_rankings << std::endl;
        while (ranked < max_rankings)
        {
            curr_max = std::numeric_limits<float>::min();
            for (json::iterator it = TRANSACTIONS_JSON.begin(); it != TRANSACTIONS_JSON.end(); ++it)
            {

                if ((*it)["Amount"] >= curr_max && (*it)["Amount"] < static_max && (*it)["T_Ranked"] != true)
                {
                    TOP_JSON[T_O_A_T] = (*it);
                    curr_max = (*it)["Amount"];
                }
            }
            static_max = curr_max;
            TOP_JSON[T_O_A_T]["T_Ranked"] = true;
            T_O_A_T = TOP_JSON.size();
            ranked++;
        } // end while
        /*
        for (json::iterator it = RANKS_JSON.begin(); it != RANKS_JSON.end(); ++it)
        {
            std::cout << (*it)["THIS->STRING: "] << std::endl;
        } */
    }
    std::string deleteTrans(int id)
    {

        int mtr, ytr;
        bool change = false;
        for (json::iterator it = TRANSACTIONS_JSON.begin(); it != TRANSACTIONS_JSON.end(); ++it)
        {
            if ((*it)["ID"] == id)
            {

                mtr = (*it)["Date->Month"];
                // int y = USER_JSON["MONTH_COUNTER"][mtr - 1];
                // USER_JSON["MONTH_COUNTER"][mtr - 1] = (y-1);
                (MONTH_COUNT[mtr - 1])--;
                ytr = (*it)["Date->Month"];
                int t = USER_JSON["A_O_T"];
                USER_JSON["A_O_T"] = (t - 1);
                change = true;
                float uy = USER_JSON["Balance"];
                float ui = (*it)["Amount"];
                USER_JSON["Balance"] = uy + ui;
                for (int i = 0; i < 12; i++)
                {
                    USER_JSON["MONTH_COUNTER"][i] = MONTH_COUNT[i];
                }
                TRANSACTIONS_JSON.erase(it);
                recordDebits();

                break;
            }
        }
        if (change == true)
        {
            establishRanks(mtr, ytr);
        }
        establishTop();
        return TRANSACTIONS_JSON.dump();
    }

}

using namespace GLOBAL_VARS;

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

    std::string getMonthString(int i) { return months[i - 1]; }

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

        std::ostringstream os;
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
// end of DATE

class TRANS_HANDLE
{
public:
    TRANS_HANDLE(std::string name, Date *date, float amount)
    {
        this->name = name;
        this->date = date;
        this->amount = amount;
        this->recorded = false;
        this->ranked = false;
    }

    std::string getTransString()
    {
        std::ostringstream os;
        os << "ID: ";
        os << this->id;
        os << " | Name: ";
        os << this->name;
        os << " | Date: ";
        os << this->date->getDateString();
        os << " | Amount: ";
        os << this->amount;

        return os.str();
    }

    // parm = text read by java from transactions.json
    // returns a the json variable dumped
    std::string addTrans(std::string t)
    {
        TRANSACTIONS_JSON = json::parse(t);
        A_O_T = TRANSACTIONS_JSON.size();
        TRANSACTIONS_JSON[A_O_T]["Name"] = this->name;
        TRANSACTIONS_JSON[A_O_T]["Date"] = this->date->getDateString();
        TRANSACTIONS_JSON[A_O_T]["Date->Month"] = this->date->getMonth();
        this->id = (A_O_T + 1);
        TRANSACTIONS_JSON[A_O_T]["ID"] = this->id;
        // std::cout<<std::endl << months[this->date->getMonth() - 1] << " -- " << MONTH_COUNT[this->date->getMonth() - 1] << std::endl;
        (MONTH_COUNT[this->date->getMonth() - 1])++;
        // std::cout<<std::endl << months[this->date->getMonth() - 1] << " -- " << MONTH_COUNT[this->date->getMonth() - 1] << std::endl;
        TRANSACTIONS_JSON[A_O_T]["Date->Day"] = this->date->getDay();
        TRANSACTIONS_JSON[A_O_T]["Date->Year"] = this->date->getYear();
        TRANSACTIONS_JSON[A_O_T]["Amount"] =( this->amount);
        TRANSACTIONS_JSON[A_O_T]["ATTRIBUTE->RECORDED_BOOL"] = false;
        TRANSACTIONS_JSON[A_O_T]["T_Ranked"] = false;
        TRANSACTIONS_JSON[A_O_T]["Ranked"] = false;
        TRANSACTIONS_JSON[A_O_T]["THIS->STRING"] = this->getTransString();
        float temp_bal = USER_JSON["Balance"];
        USER_JSON["Balance"] = temp_bal - this->amount;
        USER_JSON["A_O_T"] = TRANSACTIONS_JSON.size();
        recordDebits();
        // establishRanks();

        for (int i = 0; i < 12; i++)
        {
            USER_JSON["MONTH_COUNTER"][i] = MONTH_COUNT[i];
            // std::cout << MONTH_COUNT[i] << std::endl;
        }
        establishTop();
        return TRANSACTIONS_JSON.dump();
    }

    ~TRANS_HANDLE() {}

private:
    std::string name;
    Date *date;
    float amount;
    bool recorded;
    bool ranked;
    int id;
};

class USER_HANDLE
{
public:
    // java should open the user.json regardless, ift its empty it should return ""
    USER_HANDLE(std::string CON_PARM_USER, std::string CON_PARM_TRANS)
    {
        srand((unsigned int)time(NULL));

        if (CON_PARM_USER.compare("") == 0)
        {
            USER_JSON = {{"MONTH_COUNTER", {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, {"Name", "FirstName LastName"}, {"Username", "name"}, {"Password", ""}, {"A_O_T", 0}, {"Budgets", {}}, {"Balance", 0}, {"Scores", {}}, {"SumDebits", 0}};
        }
        else
        {
            USER_JSON = json::parse(CON_PARM_USER);
            for (int i = 0; i < 11; i++)
            {
                MONTH_COUNT[i] = USER_JSON["MONTH_COUNTER"][i];
            }
        }
        if (!(CON_PARM_USER.compare("") == 0))
        {
            TRANSACTIONS_JSON = json::parse(CON_PARM_TRANS);
        }
    } // end of constructor

    void addBudget(float amount)
    {
        A_O_B = (USER_JSON["Budgets"] != NULL) ? USER_JSON["Budgets"].size() : 0;
        // std::cout << A_O_B << std::endl;
        USER_JSON["Budgets"][A_O_B] = amount;
        recordDebits();
        float temp = USER_JSON["SumDebits"];
        A_O_B = USER_JSON["Budgets"].size();
        for (int i = 0; i < A_O_B; i++)
        {
            float currBud = USER_JSON["Budgets"][i];
            USER_JSON["Scores"][i] = (((currBud - temp) / currBud) * 10 < 0) ? 0 : ((currBud - temp) / currBud) * 10;
        }
        USER_JSON["Balance"] = correctBalance(amount);
    }

    // std::string recordDebits(std::string trans_parm, std::string user_parm)

    std::string getUSER_FIELD(std::string s)
    {
        if (s.compare("Budget") == 0)
        {
            int a = USER_JSON["Budgets"].size() - 1;
            return to_string(USER_JSON["Budgets"][a]);
        }

        if (s.compare("Score") == 0)
        {
            int a = USER_JSON["Scores"].size() - 1;
            return to_string(USER_JSON["Scores"][a]);
        }
        return to_string(USER_JSON[s]);
    }

    void setName(std::string name) { USER_JSON["Name"] = name; }
    void setUsername(std::string name) { USER_JSON["Username"] = name; }
    void setPassword(std::string pswd)
    {
        std::string temp = pswd;
        for (int i = 0; i < pswd.length(); i++)
        {
            temp[i] = (pswd[i] + 1);
        }
        USER_JSON["Password"] = temp;
    }

    std::string USERDUMP()
    {
        std::ostringstream os;
        os << std::setw(4) << USER_JSON;
        return os.str();
    }

    std::string RANK_STRING_DUMP()
    {
        std::ostringstream os;

        for (json::iterator it = RANKS_JSON.begin(); it != RANKS_JSON.end(); ++it)
        {
            os << (*it)["THIS->STRING"] << "\n";
            // std::cout << os.str() << "-----------" <<std::endl;
        }
        return os.str();
    }

    std::string getReportString()
    {
        return reportString;
    }

    bool checkPass(std::string check)
    {
        std::string temp = USER_JSON["Password"];
        std::string b_check = check;
        for (int i = 0; i < check.length(); i++)
        {
            b_check[i] = (check[i] + 1);
        }
        bool b = (b_check.compare(temp) == 0) ? true : false;
        return b;
    }

    bool checkUsername(std::string check)
    {
        std::string temp = USER_JSON["Username"];
        bool b = (check.compare(temp) == 0) ? true : false;
        return b;
    }

    std::string TRANSDUMP()
    {
        std::ostringstream os;
        os << std::setw(4) << TRANSACTIONS_JSON;
        return os.str();
    }

    std::string BUDGETSDUMP()
    {
        int q = (USER_JSON["Budgets"].size() > 3) ? 3 : USER_JSON["Budgets"].size();
        std::ostringstream os;
        os << "Budget/Score\n";
        for (int i = q - 1; i > -1; --i)
        {
            os << USER_JSON["Budgets"][i] << "/" << USER_JSON["Scores"][i] << "\n";
            if ()
        }
        return os.str();
    }

    std::string RANKSDUMP()
    {
        std::ostringstream os;
        os << std::setw(4) << RANKS_JSON;
        return os.str();
    }

    std::string TOPDUMP()
    {
        std::ostringstream os;
        os << std::setw(4) << TOP_JSON;
        return os.str();
    }

    ~USER_HANDLE() {}

private:
}; // end of class
