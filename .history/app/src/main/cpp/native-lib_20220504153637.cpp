#include <jni.h>
#include <string>
#include "headers/components.hpp"

#include <cstdlib>
#include <ctime>

TRANS_HANDLE *t;
USER_HANDLE *u;

/*
extern "C" jstring Java_com_kyeou_expensetracker_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject  this ) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
*/

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_AddExpense_addTrans(JNIEnv *env, jobject, jstring name, int day, int month, int year, float amount, jstring TRANS_JSON_PARM)
{
    std::string ret = (new TRANS_HANDLE(env->GetStringUTFChars(name, nullptr), new Date(month, day, year), amount))->addTrans(env->GetStringUTFChars(TRANS_JSON_PARM, nullptr));
    return env->NewStringUTF(ret.c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_AddExpense_getUSERSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->USERDUMP().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_AddExpense_getTRANSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->TRANSDUMP().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_SignupPage_getUSERSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->USERDUMP().c_str());
}
extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_SignupPage_getTRANSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->TRANSDUMP().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_NewUserFunds_getUSERSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->USERDUMP().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_MainActivity_getUSERINFO(JNIEnv *env, jobject, jstring stringCALL)
{
    return env->NewStringUTF((u->getUSER_FIELD(env->GetStringUTFChars(stringCALL, nullptr))).c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_ReportResult_getUSERINFO(JNIEnv *env, jobject, jstring stringCALL)
{
    return env->NewStringUTF(u->getUSER_FIELD(env->GetStringUTFChars(stringCALL, nullptr)).c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_VerifyLogin_userLogIn(JNIEnv *env, jobject, jstring user_info_json, jstring trans_info_json)
{
    u = new USER_HANDLE(env->GetStringUTFChars(user_info_json, nullptr), env->GetStringUTFChars(trans_info_json, nullptr));
    return env->NewStringUTF(u->USERDUMP().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_loginPage_userLogIn(JNIEnv *env, jobject, jstring user_info_json, jstring trans_info_json)
{
    u = new USER_HANDLE(env->GetStringUTFChars(user_info_json, nullptr), env->GetStringUTFChars(trans_info_json, nullptr));
    return env->NewStringUTF(u->USERDUMP().c_str());
}
extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_MainActivity_userLogIn(JNIEnv *env, jobject, jstring user_info_json, jstring trans_info_json)
{
    u = new USER_HANDLE(env->GetStringUTFChars(user_info_json, nullptr), env->GetStringUTFChars(trans_info_json, nullptr));
    return env->NewStringUTF(u->USERDUMP().c_str());
}
extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_SignupPage_userSignUp(JNIEnv *env, jobject, jstring user_info_json, jstring trans_info_json)
{
    // u = new USER_HANDLE(env->GetStringUTFChars(user_info_json, nullptr), env->GetStringUTFChars(trans_info_json, nullptr));
    u = new USER_HANDLE(env->GetStringUTFChars(user_info_json, nullptr), "[]");

    return env->NewStringUTF(u->USERDUMP().c_str());
}
extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_SignupPage_addBudget(JNIEnv *env, jobject, float amount)
{
    u->addBudget(amount);
}
extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_SignupPage_setName(JNIEnv *env, jobject, jstring name)
{
    u->setName(env->GetStringUTFChars(name, nullptr));
}
extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_SignupPage_setUsername(JNIEnv *env, jobject, jstring name)
{
    u->setUsername(env->GetStringUTFChars(name, nullptr));
}

extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_SignupPage_setPassword(JNIEnv *env, jobject, jstring name)
{
    u->setPassword(env->GetStringUTFChars(name, nullptr));
}

extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_NewUserFunds_addBudget(JNIEnv *env, jobject, float amount)
{
    u->addBudget(amount);
}

extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_PersonalInformation_setName(JNIEnv *env, jobject, jstring name)
{
    u->setName(env->GetStringUTFChars(name, nullptr));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_PersonalInformation_getUSERSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->USERDUMP().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_deleteExpensePage_getUSERSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->USERDUMP().c_str());
}

///////////////////////////////////////////////////////////////////////////////////////////
extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_Reports_genReport(JNIEnv *env, jobject, int month1, int y1)
{
    //  establishRanks(day1, month1, year1, day2, month2, year2);
    // establishRanks(env->GetStringUTFChars(month, nullptr));
    // J31, F28, M31, A30, M31, J30, J31, A31, S30, O31, N30, D31

    establishRanks(month1, y1);


    //std::ostringstream os;

    //for (json::iterator it = RANKS_JSON.begin(); it != RANKS_JSON.end(); ++it)
   // {
     //   os << (*it)["THIS->STRING "] << "\n";
   // }
    //return env->NewStringUTF(os.str().c_str());
}





extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_MainActivity_showTop(JNIEnv *env, jobject)
{
    //  establishRanks(day1, month1, year1, day2, month2, year2);
    // establishRanks(env->GetStringUTFChars(month, nullptr));
    // J31, F28, M31, A30, M31, J30, J31, A31, S30, O31, N30, D31

    establishTop();

    std::ostringstream os;

    for (json::iterator it = TOP_JSON.begin(); it != TOP_JSON.end(); ++it)
    {
        os << (*it)["THIS->STRING"] << "\n";
    }
    return env->NewStringUTF(os.str().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_ReportResult_showTop(JNIEnv *env, jobject)
{
    //  establishRanks(day1, month1, year1, day2, month2, year2);
    // establishRanks(env->GetStringUTFChars(month, nullptr));
    // J31, F28, M31, A30, M31, J30, J31, A31, S30, O31, N30, D31

    establishTop();

    std::ostringstream os;

    for (json::iterator it = TOP_JSON.begin(); it != TOP_JSON.end(); ++it)
    {
        os << (*it)["THIS->STRING"] << "\n";
    }
    return env->NewStringUTF(os.str().c_str());
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_kyeou_expensetracker_loginPage_checkPassword(JNIEnv *env, jobject thiz, jstring pass)
{
    return u->checkPass(env->GetStringUTFChars(pass, nullptr));
}
extern "C" JNIEXPORT jboolean JNICALL Java_com_kyeou_expensetracker_loginPage_checkUsername(JNIEnv *env, jobject thiz, jstring pass)
{
    return u->checkUsername(env->GetStringUTFChars(pass, nullptr));
}
extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_deleteExpensePage_deleteTrans(JNIEnv *env, jobject thiz, int i)
{
    return env->NewStringUTF(deleteTrans(i).c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_kyeou_expensetracker_ReportResult_getRankList(JNIEnv *env, jobject thiz) {

    return env->NewStringUTF((u->RANK_STRING_DUMP()).c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_kyeou_expensetracker_ReportResult_getRankDate(JNIEnv *env, jobject thiz) {

    return env->NewStringUTF((u->getReportString()).c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_kyeou_expensetracker_ReportResult_showBS(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(u->BUDGETSDUMP().c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_kyeou_expensetracker_PersonalInformation_setUsername(JNIEnv *env, jobject thiz,
                                                              jstring name) {
    u->setUsername(env->GetStringUTFChars(name, nullptr));
}