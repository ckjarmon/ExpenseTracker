#include <jni.h>
#include <string>
#include "headers/components.hpp"

#include <cstdlib>
#include <ctime>

extern "C" jstring Java_com_kyeou_expensetracker_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_MainActivity_addExpense (JNIEnv* env,
        jobject
        ) {

    std::ostringstream jni;
    Transaction test1("Ralphs 1", new Date(1, 1, 2000), 12.34);
    jni << test1.getTransString() << "\n";
    test1.addTrans();

    return env->NewStringUTF(jni.str().c_str());
}




