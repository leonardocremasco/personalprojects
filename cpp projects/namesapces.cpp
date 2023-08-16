
#include <iostream>

//setting the namespaces
namespace first {
    int x = 5;
}

namespace second {
    int x = 90;
}

int main (void) {
    
    using namespace second;

    std::cout << x << std::endl;
    return 0;
}

