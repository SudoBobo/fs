#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>

// some helper functions

// imitating work of HDD
// void read_lines_from_to()

// superblock struct
// indexes of inode array

// inode struct

// TODO move this structs to separate file

typedef enum {
    create_dir = 0,
    remove_dir = 1,
    list_dir = 2,

    create_file = 3,
    read_file = 4,
    write_to_file = 5,
    remove_file = 6,
} command_types;

struct Command {
    command_types command_type;
    char **operands;
};


// a hash with command first token and funcs with command creation
#define CREATE_DIR_COMMAND "create_dir"
#define REMOVE_DIR_COMMAND  "remove_dir"
#define LIST_DIR_COMMAND "list_dir"

#define CREATE_FILE_COMMAND "create_file"
#define READ_FILE_COMMAND "read_file"
#define WRITE_TO_FILE_COMMAND "write_to_file"
#define REMOVE_FILE_COMMAND "remove_file"

struct Command *create_command(char *line) {
	// try to parse 'line'
	char * token = strtok(line, " ");

	// determine type
	if (strcmp(token, CREATE_DIR_COMMAND) == 0) {

	}

	if strcmp()
	while (token != NULL) //пока есть лексемы
	{
		token = strtok (NULL, " ");
	}

	// create struct on heap
	// destroy struct if it is passed to server

	// put other tokens as operands

	// return struct


	// try patterns one by one


	// try to get tokens from line
	// we have some patterns and try to put
	// if it is not possible, return NULL
	// if parsed line does not form a command (check with enum) return NULL
	// else allocate and return struct Command *
};

int main() {
	// look for FS file in current directory
	// read superblock - create meta data as in-memory structure

	// init networking
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	// enter eternal loop waiting for commands
	char line[1024];

	while (true) {
		scanf("%1023[^\n]", line);
		Command *command = create_command(line);
		if (command == NULL) {
			printf("%s\n", INPUT_ERROR);
		} else {
			command->execute();
			//		}
			//	}
			//	// commands:
			//	// 1) create dir
			//	// 2) delete dir
			//	// 3) create file
			//	// 4) delete file
			//	// 5) read file (to std-out)
			//	// 6) list dir (to std-out)
			//	// exit by CS
			return 0;
		}