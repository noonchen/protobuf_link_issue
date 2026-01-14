#include "ser.h"
#include "test.pb.h"
#include <string>
#include <iostream>

extern "C" SER_API size_t ser(const char* msg) {
    if (!msg) return 0;

    test::RetStatus status1;
    status1.set_success(true);
    status1.set_message("static str");

    std::string tmp;
    status1.SerializeToString(&tmp);
    std::cout << tmp.size() << std::endl;

    test::RetStatus status2;
    status2.set_success(true);
    status2.set_message(std::string("std string"));

    tmp.clear();
    status2.SerializeToString(&tmp);
    std::cout << tmp.size() << std::endl;

    test::RetStatus status3;
    status3.set_success(true);
    status3.set_message(msg);

    std::string out;
    if (status3.SerializeToString(&out)) {
        return out.size();
    }
    return 0;
}
