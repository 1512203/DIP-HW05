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
        //
    }
    else if (command == COMMAND_GRAD_PREWITT) {
        //
    }
    else if (command == COMMAND_GRAD_ROBERTS) {
        //
    }
    else if (command == COMMAND_GRAD_SCHARR) {
        //
    }
    else if (command == COMMAND_LAPLACIAN) {
        //
    }
    else if (command == COMMAND_LOG) {
        //
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
