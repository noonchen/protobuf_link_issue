#include "ser.h"
#include "test.pb.h"
#include <string>

extern "C" SER_API size_t ser(const char* msg) {
    if (!msg) return 0;

    test::RetStatus status;
    status.set_success(true);
    status.set_message(msg);

    std::string out;
    if (status.SerializeToString(&out)) {
        return out.size();
    }
    return 0;
}
