#include <jni.h>
#include <string>
#include "components.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_kyeou_expensetracker_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_kyeou_expensetracker_MainActivity_stringFromJNI2(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
