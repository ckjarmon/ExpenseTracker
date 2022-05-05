
#include "components.hpp"

int main()
{
    //Simulatiung user creating an account
    printf("\n");
    USER_HANDLE u("", "[]");
    u.setName("Christian Jarmon");
    u.setUsername("kyeou");
    u.setPassword("abcd");
    u.addBudget(50);
    u.addBudget(100);

    //User is adding some transactions
    (new TRANS_HANDLE("Test Transaction 1", new Date(1, 1, 2022), 1.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 1324", new Date(1, 1, 2022), 1.32))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 12341", new Date(1, 1, 2022), 1.33))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 2", new Date(2, 2, 2022), 2.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 3", new Date(3, 3, 2022), 3.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 4", new Date(4, 4, 2022), 4.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 5", new Date(5, 5, 2022), 5.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 6", new Date(6, 6, 2022), 6.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 7", new Date(7, 7, 2022), 7.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 8", new Date(8, 8, 2022), 8.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 9", new Date(9, 9, 2022), 9.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 10", new Date(10, 10, 2022), 10.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 11", new Date(11, 11, 2022), 11.00))->addTrans(u.TRANSDUMP());
    (new TRANS_HANDLE("Test Transaction 12", new Date(12, 12, 2022), 12.00))->addTrans(u.TRANSDUMP());
    
    //User decides to delete a transaction.
    deleteTrans(1);

    //Backend API calls these functions for the Report
    establishRanks(1, 2022);
    establishTop();

    //Validation Console Dump
    printf("\nUSER INFO --------------------------------------------------------------------------------------------\n\n");
    std::cout << u.USERDUMP() << std::endl << std::endl;
    printf("\nTRANSACTIONS --------------------------------------------------------------------------------------------\n\n");
    std::cout << u.TRANSDUMP() << std::endl;
    printf("\nRANKS --------------------------------------------------------------------------------------------\n\n");
    std::cout << u.RANKSDUMP() << std::endl;
    printf("\nTOP --------------------------------------------------------------------------------------------\n\n");
    std::cout << u.TOPDUMP() << std::endl;
    printf("\nBUDGETS/SCORES --------------------------------------------------------------------------------------------\n\n");
    std::cout << u.BUDGETSDUMP() << std::endl;

    //Main dashboard info test.
    std::string user_name = u.getUSER_FIELD("Name");
    std::string balance = u.getUSER_FIELD("Balance");
    std::string budget = u.getUSER_FIELD("Budget");
    std::string score = u.getUSER_FIELD("Score");

    std::cout << "\n"
              << user_name << " " << balance << " " << budget << " " << score << " " << std::endl
              << std::endl;

    printf("Password Check (Should be 1): %zu\n", u.checkPass("abcd"));
   // printf("\n\n\n%s\t\t%s", u.getReportString(), u.RANK_STRING_DUMP());
   std::cout << "\n\n\n" << u.getReportString() << "\n" <<  u.RANK_STRING_DUMP() << std::endl;


}

