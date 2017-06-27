// Copyright 2017 Nazarov Aleksandr

#include "include/deque_text_editor_app.h"
#include "include/deque.h"

#include <iostream>
#include <string>

DequeTextEditorApp::DequeTextEditorApp(): message_("") {
    load_ = false;
    save_ = false;
    front_ = true;
    write_ = false;
    second_arguments_ = false;
    sec_arg_load_ = false;
    sec_arg_save_ = false;
    sec_arg_front_ = true;
    sec_arg_write_ = false;
}

void DequeTextEditorApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is deque of strings application.\n\n" +
        "Please provide arguments in the following format" +
        " (* - optional ability):\n\n" +

        "  $ " + appname + " -<flags1> <file_name1> " +
        "<string1> <string2> ... <stringN>" +
        " -<flags2>* <file_name2>* \n\n"

        "Mandatory flags: \n" +
        "-l -s - load/save from/into file, can be use at the same time \n" +
        "Optional flags: \n" +
        "-b -f - back/front insert\n" +
        "-w    - write on console deque elements after work";
}

std::string DequeTextEditorApp::operator()(int argc, const char** argv) {
    Deque first_deq;

    if (!argValidate(argc, argv)) {
        return message_;
    }

    for (int i = 1; argv[1][i] != '\0'; i++) {
        switch (argv[1][i]) {
        case 'l':
            load_ = true;
            break;
        case 's':
            save_ = true;
            break;
        case 'b':
            front_ = false;
            break;
        case 'f':
            front_ = true;
            break;
        case 'w':
            write_ = true;
            break;
        }
    }

    if (argc > 4 && argv[argc - 2][0] == '-' && argv[argc - 2][1] != '\0') {
        second_arguments_ = true;
        for (int i = 1; argv[argc - 2][i] != '\0'; i++) {
            switch (argv[argc - 2][i]) {
            case 'l':
                sec_arg_load_ = true;
                break;
            case 's':
                sec_arg_save_ = true;
                break;
            case 'b':
                sec_arg_front_ = false;
                break;
            case 'f':
                sec_arg_front_ = true;
                break;
            case 'w':
                sec_arg_write_ = true;
                break;
            }
        }
    }

    try {
        if (load_) {
            first_deq.Load(argv[2]);
        }

        for (int i = 3; i < ((second_arguments_) ? argc - 2 : argc); i++) {
            if (front_) {
                first_deq.InsFront(std::string(argv[i]));
            } else {
                first_deq.InsBack(std::string(argv[i]));
            }
        }

        if (save_) {
            first_deq.Save(argv[2]);
        }

        if (write_) {
            Deque buffer(first_deq);
            while (!buffer.IsEmpty()) {
                message_ += buffer.GetBack() + '\n';
            }
        }

        if (second_arguments_) {
            Deque second_deq(first_deq);

            if (sec_arg_load_) {
                second_deq.Load(argv[argc - 1]);

                for (int i = 3; i < argc - 2; i++) {
                    if (sec_arg_front_) {
                        second_deq.InsFront(std::string(argv[i]));
                    } else {
                        second_deq.InsBack(std::string(argv[i]));
                    }
                }
            }

            if (sec_arg_save_) {
                second_deq.Save(argv[argc - 1]);
            }

            if (sec_arg_write_) {
                Deque buffer(second_deq);
                while (!buffer.IsEmpty()) {
                    message_ += buffer.GetBack() + '\n';
                }
            }
        }
    }
    catch (const char* err) {
        return std::string(err);
    }

    return message_;
}

bool DequeTextEditorApp::argValidate(int argc, const char** argv) {
    if (argc > 3) {
        if (argv[1][0] != '-' || argv[1][1] == '\0') {
            help(argv[0], "wrong arguments, you don't write falgs");
            return false;
        }
        for (int i = 1; argv[1][i] != '\0'; i++) {
            if (argv[1][i] != 'l' && argv[1][i] != 's' && argv[1][i] != 'b' &&
                argv[1][i] != 'f' && argv[1][i] != 'w') {
                help(argv[0], "wrong flags");
                return false;
            }
        }

        if (argc > 4 && argv[argc - 2][0] == '-' && argv[argc - 2][1] != '\0') {
            for (int i = 1; argv[argc - 2][i] != '\0'; i++) {
                if (argv[argc - 2][i] != 'l' && argv[argc - 2][i] != 's' &&
                    argv[argc - 2][i] != 'b' && argv[argc - 2][i] != 'f' &&
                    argv[argc - 2][i] != 'w') {
                    help(argv[0], "wrong second flags");
                    return false;
                }
            }
        }
        for (int i = 2; i < argc - 2; i++) {
            if (argv[i][0] == '-') {
                help(argv[0], "too much flags");
                return false;
            }
        }
    } else {
        help(argv[0], "wrong numbers of arguments");
        return false;
    }
    return true;
}
