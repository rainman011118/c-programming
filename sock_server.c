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
#include<sys/wait.h>
#include<signal.h>

#define PORT "7767" //NOTE: This has to be inside "" since it is passed as a string in getaddrinfo
#define BACKLOG 5
// #####################################  SOCK_SERVER  ###################################################
// This is copied exactly from Beej's webpage, and works with BOTH sockets_client AND sock_client
// BUT IT IS NOT WORKING PROPERLY.....fails at accept: bad file descriptor and infinite loop..???? If I removed the while loop and use exit instead of continue, it works fine.  If I keep the while loop and use exit, then all the print statements execute with 'accept: bad file descriptor at end' which implies it is on the 2nd loop when it tries to accept another connection that is fails.  So it appears to be continually trying to accept multiple connections everytime instead of just accepting one, and stopping.???

void sigchld_handler(int s) {
		// waitpid() might overwrite errno, so we save and restore it
		int saved_errno = errno;
		while(waitpid(-1, NULL, WNOHANG) > 0) {
				errno = saved_errno;
		}
}
// get sockaddr, IPv4 or IPv6
void* get_in_addr(struct sockaddr* sa) {
		if(sa->sa_family == AF_INET) {
				return &(((struct sockaddr_in*)sa)->sin_addr);
		}
		return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void) {
		int sockfd, new_fd;
		struct addrinfo hints, *servinfo, *p;
		struct sockaddr_storage their_addr;  // Connector's address information
		socklen_t sin_size;
		struct sigaction sa;
		int yes = 1;
		char s[INET6_ADDRSTRLEN];
		int rv;

// *****************  INTITIALZE STRUCTURE  *****************************

		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_flags = AI_PASSIVE; // Use my ip

//  ***************************  COLLECT SERVER INFO FOR SERVER SOCKET  **********************

		if((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
				fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
				return 1;
		}

//  ***************** CREATE SERVER SOCKET AND BIND ***********************************

		// Go through the linked list, create SERVER socket and BIND.
		// Why do I need a linked list for this, surely there is only 1 socket for the server....??
		for(p = servinfo; p != NULL; p = p->ai_next) {
				if((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
						perror("server: socket");
						continue;
				}
				if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
						perror("setsockopt");
						exit(1);
				}
				if(bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
						close(sockfd);
						perror("server: bind");
						continue;
				}
				break;
		}
		freeaddrinfo(servinfo);
		if(p==NULL) {
				fprintf(stderr, "server: failed to bind\n");
				exit(1);
		}

//  ********************  LISTEN FOR CONNECTIONS  **********************

		if(listen(sockfd, BACKLOG) == -1) {
				perror("listen");
				exit(1);
		}
		sa.sa_handler = sigchld_handler; // Reap all dead processes
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_RESTART;
		if(sigaction(SIGCHLD, &sa, NULL) == -1) {
				perror("sigaction");
				exit(1);
		}
		printf("server: waiting for connections...\n");

		// THIS ACCEPT PART IS STILL FUCKING UP!! AND INFINTIE LOOPING!!!  WHY??????????????? Is it the socklen_t??  If I remove the while loop it works ok.  It would appear that the first accept is successful, but the following one isn't (BECAUSE THERE ISN'T ONE!) ...... I even tried with 'break' but it still does the same infinte loop??  It must be the fork process then....??
		// main accept loop
//		while(1) {
		sin_size = sizeof(their_addr);
		//Below, accept stores the address of the connecting machine in 'their_addr struct'
		new_fd = accept(sockfd, (struct sockaddr*)&their_addr, &sin_size);
		if(new_fd == -1) {
				perror("accept");
				exit(1);
		}
		printf("accept successful\n");


// **********************  DISPLAY IPADDRESS OF CLIENT  ************************

		inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr*)&their_addr), s, sizeof(s));
		printf("server: got connection from %s\n", s);
		

		//I don't get this part:   why fork???   are brackets missing in BEEJ's copy????  
		//I FINALLY GET THIS: After getting rid of the while(1) loop and adding some of these print statements to see who is the parent and who is the child, it would appear that the connection is accepted, then the parent completes first (outside of the !fork()) loop, by closing the new_fd (since it will let the child process deal with this. Then the child executes, firstly closing the main server socket( not needed in child), then sends the message, then closes itself at end.
		if(!fork()) { // This is the child process
				close(sockfd); // Child doesn't need the listener
				printf("fork sockfd closed\n");
				if(send(new_fd, "Hello, world!", 13, 0) == -1) {
						perror("send");
						close(new_fd);
						exit(0);
				}
				printf("fork Message sent\n");
		}
		printf("Process id = %d, Parent id = %d\n", getpid(), getppid());
		close(new_fd); // Parent doesn't need this
		printf("outside new_fd closed\n");

		return 0;
}


