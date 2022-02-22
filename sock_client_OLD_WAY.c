#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h> // This is for the inet_addr to work

// #########################  CLIENT SIDE  ########################################

// THIS IS CONSIDERED THE OLD WAY OF DOING THINGS.....(see sock_client.c for new way)
// MUST SEE: https://beej.us/guide/bgnet/html//index.html

//#define PORT 7777

int main(int argc, char** argv) {
		char server_response[256];
//		char* ip4 = "127.0.0.1";
		int sockfd, connection_status, z;

		// If I input a different ip address than the server, then it just blinks......and nothing happens.   (Is it trying to connect to that specified ip on the port specified, I wonder if these leaves a log on the other ip????)

// **************  CHECK THE COMMAND LINE INPUT - useful as guide to remember order for particular servers....
		if(argc != 3) {
				printf("Usage: %s hostname port\n", argv[0]);
				exit(1);
		}

		// This bit converts the port input from string to long for the .sin_port = htons(result) below
		// but likely not necessary since I would have the port number #defined (if regular use)
		char* ptr = NULL;
		uint16_t port = strtol(argv[2], &ptr, 10); 

// ***********************	FILL THE STRUCT INFORMATION  ***********************

		struct sockaddr_in servaddr;
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(port);
//		servaddr.sin_addr.s_addr = INADDR_ANY;
//		servaddr.sin_addr.s_addr = inet_addr(ip4);
		// ERROR CHECK IP ADDRESS FOR CORRECT FORMAT
		z = inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
		if(z <= 0) {
				if(z == 0) {
						fprintf(stderr, "Not in dots-notation format\n");
						return(1);
				}else {
						perror("inet_pton");
						exit(1);
				}
		}

		// CREATE THE SOCKET
		if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
				perror("Error in creating socket");
				exit(1);
		}
		// CONNECT:
		if((connection_status = connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) == -1) {
				perror("Error on connect()");
				exit(1);
		}
		// RECEIVE DATA FROM THE SERVER;
		recv(sockfd, &server_response, sizeof(server_response), 0);
		printf("The server sent this data: %s\n", server_response);

		// CLOSE THE SOCKET;
		close(sockfd);
		printf("socket closed\n");

		return 0;

