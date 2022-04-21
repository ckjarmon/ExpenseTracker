#include "components.hpp"

int main() {
    std::string ret = (new TRANS_HANDLE(env->GetStringUTFChars(name, nullptr), new Date(month, day, year), amount))->addTrans(env->GetStringUTFChars(TRANS_JSON_PARM, nullptr));
 std::cout << ret
}