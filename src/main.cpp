#include "common.h"
#include "BaseProcessor.h"
#include "EdgeDetector.h"


int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << ERROR_MESS_INVALID_ARGUMENTS << endl;
        return -1;
    }

    string pathToImage = string(argv[1]);
    string command = string(argv[2]);

    BaseProcessor* proc = new EdgeDetector(pathToImage);
    argv_t kwargs;

    if (command == COMMAND_GRAD_SOBEL) {
        kwargs["threshold"] = (argc >= 4) ? argv[3] : "-1";
    }
    else if (command == COMMAND_GRAD_PREWITT) {
        kwargs["threshold"] = (argc >= 4) ? argv[3] : "-1";
    }
    else if (command == COMMAND_GRAD_ROBERTS) {
        kwargs["threshold"] = (argc >= 4) ? argv[3] : "-1";
    }
    else if (command == COMMAND_GRAD_SCHARR) {
        kwargs["threshold"] = (argc >= 4) ? argv[3] : "-1";
    }
    else if (command == COMMAND_LAPLACIAN) {
        kwargs["threshold"] = (argc >= 4) ? argv[3] : "-1";
    }
    else if (command == COMMAND_LOG) {
        kwargs["kernel_size"] = (argc >= 4) ? argv[3] : "5";
        kwargs["sigma"] = (argc >= 5) ? argv[4] : "1.4";
        kwargs["threshold"] = (argc >= 6) ? argv[5] : "-1";
    }
    else if (command == COMMAND_CANNY) {

    }
    else {
        cerr << ERROR_MESS_INVALID_COMMANDS << endl;
        return -1;
    }

    kwargs["filter"] = command;
    proc->execute(kwargs);
    delete proc;
    return 0;
}
