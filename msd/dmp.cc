#include "dmp_diff.hpp"
#include <iostream>
#include <string>

using namespace std;

using MyersStringDiff = MyersDiff<string>;

int main(int argn, char** args) {
    string one{"testtextparzivalabcdefg"};
    string two{"textextparzivalacdef"};
    MyersStringDiff diff{one, two};

    for (const auto &i : diff) {
        cout << i.str() << endl;
    }

    return 0;
}
