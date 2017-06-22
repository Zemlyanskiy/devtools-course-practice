#include "include/Demand_app.h"

int main(int argc, const char** argv) {
    DemandApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
