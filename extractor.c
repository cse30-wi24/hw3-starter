#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LEN 1024 // including null terminator
#define USAGE_FORMAT_STR "ERR: expected usage is %s -c <in_cols> [-d delimiter] [-s] col1 ...\n"

int main(int argc, char **argv) {
	int in_cols = 0; // number of columns in input
	int out_cols = 0; // number of columns to output

	bool c_flag = false; // keep track of whether or not we received the required c flag
	bool stats_flag = false; // keep track of whether -s flag is passed in or not

	char delim = ','; // keep track of the delimiter, by default it is a comma

	// local variables to store the statistics
	unsigned int lines = 0; // number of lines in input
	size_t max_len = 0; // longest field in input
	size_t output_size = 0; // total output printed in characters

	// TODO: process named command line options using getopt and store the information in the
	// appropriate local variables
	int c;
	/* TODO: fill out this skeleton code calling getopt */
	while ((c = getopt(argc, argv, "s" /* TODO: fix argument to getopt */)) != -1) {
		switch (c) {
		case 's':
			stats_flag = 1;
			break;
		/*
		TODO: fill in remaining cases (c flag, d flag)
		- You will want to use the optarg variable set by getopt, to access option args
		- You will want to use atoi to convert strings to integer types
		*/
		default:
			fprintf(stderr, USAGE_FORMAT_STR, argv[0]);
			return EXIT_FAILURE;
		}
	}

	// TODO: uncomment following block & check to make sure c argument was provided
	/*
	if ( -FILL IN- ) {
		// we did not receive the required c option, print usage and terminate
		fprintf(stderr, USAGE_FORMAT_STR, *argv);
		return EXIT_FAILURE;
	}
	*/

	/* pointers to arrays which will be allocated dynamically by you */
	char **colptrs = NULL; /* pointer to array of pointers to the start of
	                         each field in input buffer */
	int *target_cols = NULL; /* pointer to array of output indices */

	// allocate arrays dynamically
	// TODO: uncomment the block below & fill in mallocs
	/*
	colptrs = malloc(sizeof(*colptrs) * (-FILL IN-)); // should be based on in_cols
	if (colptrs == NULL) { // always check if malloc failed
		return EXIT_FAILURE;
	}
	out_cols = (-FILL IN-); // should be based on argc, optind
	target_cols = malloc(sizeof(*target_cols) * out_cols);
	if (target_cols == NULL) { // always check if malloc failed
		free(colptrs);
		return EXIT_FAILURE;
	}
	*/

	// TODO: process other command line arguments (list of output columns)
	// Fill these into target_cols!

	char line[MAX_LINE_LEN]; // read buffer for processing lines in input
	// TODO: using fgets, loop over input from stdin
	// steps: read a line, parse the line as described in writeup, print target columns for this
	// line, repeat for next line, then repeat until no more lines

	// TODO: print out the statistics if -s flag is set
	printf(
		"Number of lines: %d\nLongest field: %zu characters\nOutput size: %zu characters\n",
		lines, max_len, output_size
	);

	// free the memory for arrays allocated with malloc
	// TODO: uncomment these lines when you uncomment the mallocs above
	// free(colptrs);
	// free(target_cols);
	return EXIT_SUCCESS;
}
