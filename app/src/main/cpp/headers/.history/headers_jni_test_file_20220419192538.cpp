#include "headers_jni_test_file.h"
#include "iostream"
#include "sstream"
#include "fstream"
#include "string"
#include "stdio.h"
#include "stdlib.h"
#include "json.hpp"
using json = nlohmann::json;


JNIEXPORT jstring JNICALL Java_headers_1jni_1test_1file_TESTSEQ
  (JNIEnv *env, jobject jobj, jstring s) {
    std::string sa = env->GetStringUTFChars( s, NULL);
auto j = json::parse(sa);  
std::cout << j.dump() << std::endl;
return 
  }