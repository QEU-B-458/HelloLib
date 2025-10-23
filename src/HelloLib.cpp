#include "HelloLib.h"

namespace HelloLib {
    std::string greet(const std::string& name) {
        return "Hello, " + name + " from HelloLib!";
    }
}
