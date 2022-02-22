#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT "7767" //NOTE: This has to be inside "" since it is passed as a string in getaddrinfo
#define MAXDATASIZE 100
// #####################################  SOCK_CLIENT  ###################################################
// This is copied exactly from Beej's webpage.

// Get the IPV4 or IPV6 address
void* get_in_addr(struct sockaddr *sa) {
		if(sa->sa_family == AF_INET) {
				return &(((struct sockaddr_in*)sa)->sin_addr);
		}
		return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


// DO I REALLY NEED TO USE HINTS?? IF i AM CLIENT, I WILL ONLY BE CONNECTING TO 1 SERVER.....
//

int main(int argc, char** argv) {
		int sockfd, numbytes, rv;
		char buf[MAXDATASIZE];
		struct addrinfo hints, *servinfo, *p;
		char s[INET6_ADDRSTRLEN];

		// Check for right command line arguments (I changed this to add port too - more realistic. However, having a defined PORT makes sense too, especially if it is a commonly used connection).
		if(argc != 3) {
				fprintf(stderr, "usage: %s hostname port\n", argv[0]);
				exit(1);
		}


// ********************************  INITIALIZE AND GATHER ADDRESS INFO  ****************************

		// Set structure to 0, and specify TYPE of connection
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC;			//any family ipv4 or ipv6
		hints.ai_socktype = SOCK_STREAM;		//TCP only

		// call getaddrinfo to get address, port, type of connection, and store all in servinfo.
		// replace argv[2] with PORT if necessary
		if((rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo)) != 0) {
				fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
				return 1;
		}

// ********************************** CREATE SOCKETS AND CONNECT  *************************************

		// Search through list pointed by servinfo...CREATE SOCKETS....CONNECT.
		for(p = servinfo; p != NULL; p = p->ai_next) {
				if((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
						perror("client: socket");
						continue;
				}
				if(connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
						close(sockfd);
						perror("client: connect");
						continue;
				}
				break;
		}
		if(p==NULL) {
				fprintf(stderr, "client: failed to connect\n");
				return 2;
		}

// **************************  DISPLAY CONNECTING IP ADDRESS  **********************************

		// display ipaddress of client
		inet_ntop(p->ai_family, get_in_addr((struct sockaddr*)p->ai_addr), s, sizeof(s));
		printf("client: connecting to %s\n", s);

		freeaddrinfo(servinfo);


// ************************* RECEIVE  ***************************************************

		// Check for any data received from server
		if((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
				perror("recv");
				exit(1);
		}
		buf[numbytes] = '\0';
		printf("data received: '%s'\n", buf);

		close(sockfd);
		return 0;
}


