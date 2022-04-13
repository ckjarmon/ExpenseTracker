#include <jni.h>
#include <string>
#include "components.hpp"

extern "C" JNIEXPORT jstring;

extern "C" jstring Java_com_kyeou_expensetracker_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

