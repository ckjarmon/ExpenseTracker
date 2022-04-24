#include "headers_jni_test_file.h"

using json = nlohmann::json;


JNIEXPORT void JNICALL Java_headers_1jni_1test_1file_TESTSEQ
  (JNIEnv *, jobject, jstring s) {
    std::string sa = (*env)->GetStringUTF
auto j = json::parse(s);  
std::cout << j.dump() << std::endl;
  }