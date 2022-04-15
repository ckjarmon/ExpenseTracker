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

jint Jniint() {
    srand((unsigned int) time(0));
    int intrandom = (rand() % (990 - 101)) + 101;
    return intrandom;
}



extern "C"
JNIEXPORT jint JNICALL
Java_com_kyeou_expensetracker_MainActivity_Jniint(JNIEnv *env, jobject thiz) {
    return (jint) Jniint();
}