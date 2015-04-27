/*	APOSTLE: a post-apocalyptic roguelike for Linux
 *	developed by Christian Byrne <christianbyrne2012@gmail.com>
 *
 *	apostle is in early stages of development. Bugs are guaranteed
 *	to ensue.
 *
 *	Development of apostle is carried out publicly on my GitHub repo:
 *	    https://github.com/jenerick/apostle
 *	Feel free to make a pull request or something.			*/

/* STANDARD libraries */
#include <iostream>
#include <cstring>

enum	argid {
	/* argument identifiers */
	ARG_HELP	= 0,
	ARG_UNKNWN
};

void	print_init_msg ( )
{
	/* the message displayed when starting apostle
	 *
	 * note: messages must not be terminated with
	 * a newline escape character '\n'.		*/
	char	*msg_init =
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
}

void	print_help_msg ( )
{
	/* message that describes usage information */
	char	*msg_help =
			(char *)
			" USAGE:\n"
			"   apostle [options]\n"
			"\n"
			" OPTIONS:\n"
			"   -h, --help:\n"
			"         display this message.";

	std::cout << msg_help << '\n';
}

argid	identify_argument ( char* arg )
{
	/* identify_argument: identifies the given argument
	 *
	 * return value:
	 * 	integer value of the associated argument.
	 */

	argid	retid = ARG_UNKNWN;

	if ( strcmp(arg, "-h") == 0 || strcmp(arg,"--help") == 0 )
		retid	= ARG_HELP;

	return	retid;
}

bool	handle_arguments ( int argc, char** argv )
{
	/* handle_arguments: handles arguments
	 * 
	 * return value:
	 * 	true:	handled arguments without error.
	 * 	false:	error occured while handling arguments.
	 */

	bool	cont = true;

	for ( int count = 1; count <= argc-1 && cont; count++ ) {
		switch ( identify_argument(argv[count]) ) {
			case ARG_UNKNWN:
				std::cerr << "error: undefined argument \'" << argv[count] 
					<< "\'.\n\n";
				/* break not needed as it will go to help */
			case ARG_HELP:
				cont	= false;
				print_help_msg ( );
				break;
			default:
				cont	= false;
				std::cerr << "error: unknown error\n\n";
				break;
		}
	}
}

int	main ( int argc, char** argv )
{
	/* beginning newline (to seperate the program output from the
	 * rest of the terminal's).					*/
	std::cout << '\n';

	/* the message displayed at the beginning of apostle's execution */
	print_init_msg ( );
	std::cout << '\n';

	handle_arguments ( argc, argv );

	/* ending newline ( same purpose as the beginning one ). */
	std::cout << '\n';
	return	0;
}
