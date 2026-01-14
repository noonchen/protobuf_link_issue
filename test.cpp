#include "test.pb.h"
#include <iostream>

int main() {

    test::RetStatus status;
    status.set_success(true);
    status.set_message("Hello");

    std::string serialized;
    if (status.SerializeToString(&serialized)) {
        std::cout << "Length: " << serialized.size() << std::endl;
    } else {
        std::cout << "Serialization failed" << std::endl;
    }

    return 0;
}