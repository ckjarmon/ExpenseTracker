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


extern "C" JNIEXPORT jstring JNICALL Java_com_kyeou_expensetracker_MainActivity_jniUSER(
        JNIEnv* env,
        jobject
        ) {

    std::ostringstream jni;
    Transaction test1("Ralphs 1", new Date(1, 1, 2000), 12.34);
    jni << test1.getTransString() << "\n";
    test1.addTrans();

    Transaction test2("Ralphs 2", new Date(1, 1, 2000), 12.34);
    jni << test2.getTransString() << "\n";
    test2.addTrans();

    Transaction test3("Ralphs 3", new Date(1, 1, 2000), 12.34);
    jni<< test3.getTransString() << "\n";
    test3.addTrans();

    Transaction test4("Ralphs 4", new Date(2, 2, 2000), 56.78);
    jni << test4.getTransString() << "\n";
    test4.addTrans();

    Transaction test5("Ralphs 5", new Date(2, 2, 2000), 56.78);
    jni << test5.getTransString() << "\n";
    test5.addTrans();

    Transaction test6("Ralphs 6", new Date(2, 2, 2000), 56.78);
    jni << test6.getTransString() << "\n";
    test6.addTrans();


    Transaction test7("Ralphs 7", new Date(2, 2, 2000), 200.00);
    jni << test7.getTransString() << "\n";
    test7.addTrans();

    return env->NewStringUTF(jni.str().c_str());
}




