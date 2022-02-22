#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h> //This is for the inet_addr to work

//######################  SERVER SIDE  ############################################### 

// BEWARE.....When I ran this, with INADDR_ANY a firewall notice popped up asking for public access..?? But when I changed it to inet_addr(loopback add), it worked fine.

#define PORT 7777

int main() {
		struct sockaddr_in servaddr;
		char* server_message = "Welcome to the server!";
		char* ipaddr = "127.0.0.1";
		int sockfd, client_socket, status;
		
// *****************************  CREATE SERVER SOCKET  *******************************	

		if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
				perror("[-]Error while creating socket");
				exit(1);
		}
		printf("[+] Server socket created\n");

// *********************************  FILL IN SERVER ADDR INFO  *************************

		//	Any of the 3 '.sin_addr.s_addr'/status work.
		memset(&servaddr, 0, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(PORT);
		servaddr.sin_addr.s_addr = INADDR_ANY; // bind to all interfaces (typical for servers...)
//		servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // Probably the easiest way to do it. 
/*		status = inet_pton(AF_INET, ipaddr, &(servaddr.sin_addr)); // error checks format of ip...too much??
		if(status <= 0) {
				if(status == 0) {
						fprintf(stderr, "Error with format of ip4 address\n");
						return(1);
				}else {
						perror("inet_pton");
						exit(1);
				}
		}
*/		
// *******************************  BIND SOCKET TO OUR SERVER INFO  ****************************

		if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
				perror("[-] Error in binding");
				exit(1);
		}
		printf("[+] Binding successful\n");

		if(listen(sockfd, 5) == -1) {// The 5 here doesn't matter, as long as it is not 0. I think it means how many connections will be allowed at once.
				perror("[-} Error in listening");
				exit(1);
		}
		printf("[+] Listening for connections...\n");


//  *************************  CREATE CLIENT SOCKET  ******************************		

//  NULL, NULL is just a short cut. Otherwise, if you wanted to get the address details of the connecting client you would have (struct sockaddr*)&sockaddr_storage, sizeof(storage)). Then you would have to call a function to get the address details from the storage struct. (SEE SOCK_SERVER)
		client_socket = accept(sockfd, NULL, NULL);

		// Send server message to client
		int msg_len = strlen(server_message);
		send(client_socket, server_message, msg_len, 0);

		// Close the SERVER connection. (Otherwise I could just close the clientsocket connection)
		close(sockfd);

		return 0;
}

