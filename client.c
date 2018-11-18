#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <zconf.h>

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


// extract it to the separate file which would be used by both server and client
#define CREATE_DIR_COMMAND "create_dir"
#define REMOVE_DIR_COMMAND  "remove_dir"
#define LIST_DIR_COMMAND "list_dir"

#define CREATE_FILE_COMMAND "create_file"
#define READ_FILE_COMMAND "read_file"
#define WRITE_TO_FILE_COMMAND "write_to_file"
#define REMOVE_FILE_COMMAND "remove_file"

bool is_valid(const char *line) {
	char *first_whitespace = memchr(line, ' ', 100);
	if (first_whitespace == NULL) {
		return false;
	}

	// check that it is known

	// CREATE_DIR
	if (memcmp(line, &create_dir, sizeof(char) * (first_whitespace - line)) == 0) {
		return true;
	}

	// REMOVE_DIR
	if (memcmp(line, &remove_dir, sizeof(char) * (first_whitespace - line)) == 0) {
		return true;
	}

	// LIST_DIR
	if (memcmp(line, &list_dir, sizeof(char) * (first_whitespace - line)) == 0) {
		return true;
	}
	// check that there are second word

	// check that there are the thrid word if it 'write_to_file' command

//	char *second_whitespace = memchr(first_whitespace + 1, ' ', 500);
//	// check that there are first word
//	if (second_whitespace == NULL) {
//		return false;
//	}

	return false;
}

#define ERROR_MESSAGE "Invalid command or/and invalid operands. Please read README.md\n"

char * send_command(int sockfd, const char* command_line, char* input_buf) {
	// write to socker raw
	// wait for an answer
	// TODO FIX TO SIZEOF(CHAR) * STRLEN
	send(sockfd , command_line , strlen(command_line) , 0);
	int valread = read(sockfd , input_buf, 1024);
	printf("%s\n",input_buf );
	// TODO check if it would clean the buffer
	input_buf = {0};
}

int main() {
	// look for FS file in current directory
	// read superblock - create meta data as in-memory structure

	// enter eternal loop waiting for commands
	char line[1024];
	char *result;

	// init socket
	int sockfd;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	struct sockaddr_in serv_addr;
	memset(&serv_addr, '0', sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(8080);

	// Convert IPv4 address from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("Invalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("Connection Failed \n");
		return -1;
	}

	// TODO READ ABOUT THIS
	char buf[1024] = {0};
	while (true) {
		scanf("%1023[^\n]", line);
		// validate first word
		if (is_valid(line)) {
			// TODO pass socket pointer to it
			send_command(sockfd, line, buf);
//			printf("%s\n", result);
 		} else {
			printf("%s\n", ERROR_MESSAGE);
		}
	}
}