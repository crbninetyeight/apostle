/*	APOSTLE: a post-apocalyptic roguelike for Linux
 *	developed by Christian Byrne <christianbyrne2012@gmail.com>
 *
 *	apostle is in early stages of development. Bugs are guaranteed
 *	to ensue.
 *
 *	Development of apostle is carried out publicly on my GitHub repo:
 *	    https://github.com/jenerick/apostle
 *	Feel free to make a pull request or something.			*/

// STANDARD libraries
#include <iostream>
#include <cstring>

// APOSTLE libraries
#include "world.hpp"

// argument identifiers
enum argid {
    ARG_HELP    = 0,    // help argument
    ARG_UNKNOWN         // an unknown argument
};

// print the init message
void print_init_msg()
{
    /* the message displayed when starting apostle
     *
     * note: messages must not be terminated with
     * a newline escape character '\n'.		*/
    char *msg_init =
        (char *)
        " APOSTLE: a post-apocalyptic roguelike\n"
        " by Christian Byrne <christianbyrne2012@gmail.com>\n"
        "                    <github.com/jenerick>\n"
        "\n"
        " DISCLAIMER:\n"
        " This   program  is  not  under  any  warranty.\n"
        " Any unfortunate losses of data or functionality\n"
        " are not protected from the user. You have been\n"
        " warned.";

    std::cout << msg_init << '\n';

    delete msg_init; // for safe measure
}

// print the help message and a short description
void print_help_msg()
{
    // message that describes usage information
    char *msg_help =
        (char *)
        " USAGE:\n"
        "   apostle [options]\n"
        "\n"
        " OPTIONS:\n"
        "   -h, --help:\n"
        "         display this message.";

    std::cout << msg_help << '\n';

    delete msg_help; // for safe measure
}

argid identify_argument(char* arg)
{
    /* identify_argument: identifies the given argument
     *
     * return value:
     * 	integer value of the associated argument.
     */

    argid retid = ARG_UNKNOWN;

    if (strcmp(arg, "-h") == 0 || strcmp(arg,"--help") == 0)
        retid = ARG_HELP;

    return retid;
}

void prompt_error(const char* msg, bool interactive)
{
    /* prompt the user an error message and (optionally) decide whether
     * to continue or not.
     *
     * arguments:
     * 	msg:		the message string to be displayed.
     * 	interactive:	wait for user input (true) or not (false).	*/

    char in;    // single character input

    if ( !interactive ) {
        // print the output to cerr as this may be suppressed.
        std::cerr << "error: " << msg << '\n';
    } else {
        // print the output to cout as the user will need to see it to continue.
        std::cout << "error: " << msg << '\n';
        // now wait for user input
        std::cin  >> in;
    }
}

bool handle_arguments(int argc, char** argv, bool *interactive)
{
    /* handle_arguments: handles arguments
     *
     * return value:
     * 	true:	handled arguments without error.
     * 	false:	error occured while handling arguments.
     */

    bool cont = true, ret = false;

    for ( int count = 1; count <= argc-1 && cont; count++ ) {
        switch ( identify_argument(argv[count]) ) {
        case ARG_UNKNOWN:
            prompt_error("unknown argument\n", false);
            // break not needed as it will go to help
        case ARG_HELP:
            cont = false;
            print_help_msg();
            *interactive = false;
            break;
        default:
            cont = false;
            prompt_error("unknown error", false);
            break;
        }
    }

    return ret;
}

void doinput(std::string *input)
{
    std::cout << "?> ";
    std::cin  >> *input;
}

int main(int argc, char** argv)
{
    std::string input;          // input string.
    bool interactive = true;    // the session will be interactive unless stated.

    std::cout << '\n';  // beginning newline to seperate apostle's output.
    print_init_msg();
    std::cout << '\n';
    handle_arguments(argc, argv, &interactive);
    if (interactive) doinput(&input);
    std::cout << '\n';

    return 0;
}
