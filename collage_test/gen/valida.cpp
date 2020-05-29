#include<fstream>

#define MAX_COLOR 255
#define MAX_LEN 1000
using namespace std;
int main(int argc, char** argv) {
    auto fIn = ifstream(argv[1]);

    int len;
    fIn >> len;
    if(fIn.fail() || len < 1 || len > 1000000) {
        return -1;
    }

    int tmp;
    for(int i = 0; i < len; i++) {
        fIn >> tmp;
        if(fIn.fail() || tmp < 0 || tmp > MAX_COLOR) {
            return -1;
        }
    }

    fIn >> tmp;
    if(fIn.fail()) {
        return 0;
    } else {
        return -1;
    }

}
