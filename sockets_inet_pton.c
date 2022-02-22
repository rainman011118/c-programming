#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h> //This was required for the inet_pton to work

//https://beej.us/guide/bgnet/html//index.html

/* inet_pton stands for 'presentation to network'. It converts an IP address from the dots notation into a struct in_addr.
It returns -1 on error and 0 if the address is messed up. So make sure to check the result is greater than 0 before using!!
 */
int main(int argc, char** argv) {
		struct sockaddr_in sa;
//		struct sockaddr_in6 sa6;

		inet_pton(AF_INET, "172.20.10.2", &(sa.sin_addr));
//		inet_pton(AF_INET6, "fe80::85f6:45de:8f9c:c4ab", &(sa6.sin6_addr));

		//This is the reverse: turning struct in_addr back into dots and numbers notation IP address:
		char ip4[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);
		printf("The IPv4 address is: %s\n", ip4);

// ################################################################################################################
		
// The following is taken straight from the 'man inet_pton' pages. It  converts the IP address input on the command line into an struct in_addr.  
/*
		unsigned char buf[sizeof(struct in_addr)];
		int domain, s;
		char str[INET_ADDRSTRLEN];

		if(argc != 3) {
				fprintf(stderr, "Usage: %s {i4|i6|<num>} string\n", argv[0]);
				exit(EXIT_FAILURE);
		}

		domain = (strcmp(argv[1], "i4") == 0) ? AF_INET : (strcmp(argv[1], "i6") == 0) ? AF_INET6 : atoi(argv[1]);
		
		s = inet_pton(domain, argv[2], buf);//takes the IP address input on the command line, converts it to network byte order, as a struct in_addr, copies it to buf. inet_pton returns 1 on success, 0 if string is incorrect format, -1 on error.
		if(s <= 0) {
				if(s == 0) {
						fprintf(stderr, "Not in presentation format");
				}else {
						perror("inet_pton");
						exit(EXIT_FAILURE);
				}
		}
		if(inet_ntop(domain, buf, str, INET_ADDRSTRLEN) == NULL) {// converts the IP address from network byte order back to dots-notation format.
				perror("inet_ntop");
				exit(EXIT_FAILURE);
		}
		printf("this is the output of the inet_ntop: %s\n", str);

*/
		return 0;
		}


