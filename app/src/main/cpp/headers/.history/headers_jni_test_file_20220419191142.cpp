#include "headers_jni_test_file.h"

using json = nlohmann::json;


JNIEXPORT void JNICALL Java_headers_1jni_1test_1file_TESTSEQ
  (JNIEnv *env, jobject jobj, jstring s) {
    std::string sa = (*env)->GetStringUTFChars(env, j, NULL);
auto j = json::parse(s);  
std::cout << j.dump() << std::endl;
  }