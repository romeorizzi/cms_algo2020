#include<fstream>

#define MAX_COLOR 255
#define MAX_LEN 1000000
#define MAX_COMPRESSED 150
using namespace std;
int main(int argc, char** argv) {
    auto fIn = ifstream(argv[1]);

    int len;
    fIn >> len;
    if(fIn.fail() || len < 1 || len > MAX_LEN) {
        return -1;
    }

    int tmp;
    int old = MAX_COLOR + 1;
    int compressedCount = 0;
    for(int i = 0; i < len; i++) {
        fIn >> tmp;
        if(fIn.fail() || tmp < 0 || tmp > MAX_COLOR) {
            return -1;
        }
        if(tmp != old) {
            compressedCount++;
            old = tmp;
        }
    }

    fIn >> tmp;
    if(fIn.fail() && compressedCount <= MAX_COMPRESSED) {
        return 0;
    } else {
        return -1;
    }

}
