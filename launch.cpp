#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        return 0;
    }

    string filename = argv[1];
    string raw_name = filename;
    if (filename.rfind('.') != string::npos) {
        raw_name = filename.substr(0, filename.rfind('.'));
    }
    string input_name = raw_name + ".in";

    string cmd = "\"" + filename + "\"";
    if (argc == 3) {
        cmd = string(argv[2]) + " " + filename;
    }
    ifstream fin(input_name.c_str());
    if (fin) {
        cmd += " < \"" + input_name + "\"";
    }
    fin.close();

    clock_t t = clock();
    system(("\"" + cmd + "\"").c_str());
    cout << endl;
    cout << "Total time: " << (clock() - t) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
    system("pause");
    return 0;
}
