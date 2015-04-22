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

int	main ( int argc, char** argv )
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

	/* beginning newline ( to seperate the program output from the
	 * rest of the terminal's ).					*/
	std::cout << '\n';

	/* the message displayed at the beginning of apostle's execution */
	std::cout << msg_init << '\n';

	/* ending newline ( same purpose as the beginning one ). */
	std::cout << '\n';
	return	0;
}
