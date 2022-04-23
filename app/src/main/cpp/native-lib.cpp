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
/*
extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_MainActivity_addExpense (JNIEnv* env,
        jobject
        ) {
std::fstream file("wtf.txt");
    USER *user = new USER();
    std::ostringstream jni;
    Transaction test1("Ralphs 1", new Date(1, 1, 2000), 12.34);
    jni << test1.getTransString() << "\n";
    test1.addTrans();

    user->USER_CLOSE();

    return env->NewStringUTF(jni.str().c_str());
}*/

// first function should take in a string from files after reading and pass it as a parameter to one of these functions
extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_AddExpense_addTrans(JNIEnv *env, jobject, jstring name, int day, int month, int year, float amount, jstring TRANS_JSON_PARM)
{
    std::string ret = (new TRANS_HANDLE(env->GetStringUTFChars(name, nullptr), new Date(month, day, year), amount))->addTrans(env->GetStringUTFChars(TRANS_JSON_PARM, nullptr));
    return env->NewStringUTF(ret.c_str());
}

/*
extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_AddExpense_recordDebits(JNIEnv *env, jobject)
{
    u->recordDebits();
}*/

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

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_NewUserFunds_getUSERSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->USERDUMP().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_SignupPage_getTRANSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->TRANSDUMP().c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_MainActivity_getUSERINFO(JNIEnv *env, jobject, jstring stringCALL)
{
    return env->NewStringUTF(u->getUSER_FIELD(env->GetStringUTFChars(stringCALL, nullptr)).c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_SignupPage_userSignUp(JNIEnv *env, jobject, jstring user_info_json, jstring trans_info_json)
{
    u = new USER_HANDLE(env->GetStringUTFChars(user_info_json, nullptr), env->GetStringUTFChars(trans_info_json, nullptr));
    return env->NewStringUTF(u->USERDUMP().c_str());
}

extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_NewUserFunds_addBudget(JNIEnv *env, jobject, float amount)
{
    u->addBudget(amount);
}

extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_SignupPage_addBudget(JNIEnv *env, jobject, float amount)
{
    u->addBudget(amount);
}

extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_SignupPage_setName(JNIEnv *env, jobject, jstring name)
{
    u->setName(env->GetStringUTFChars(name, nullptr));
}

extern "C" JNIEXPORT void JNICALL Java_com_kyeou_expensetracker_PersonalInformation_setName(JNIEnv *env, jobject, jstring name)
{
    u->setName(env->GetStringUTFChars(name, nullptr));
}

extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_PersonalInformation_getUSERSJSON(JNIEnv *env, jobject)
{
    return env->NewStringUTF(u->USERDUMP().c_str());
}
