#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>

// ########################## getaddrinfo()  ###############################################

// SEE: https://beej.us/guide/bgnet/html//index.html

// This program shows the ip addresses for a host given on the command line.
// Basically the same as the 'host <domain name>' command.

int main(int argc, char** argv) {
		int status;
		struct addrinfo hints, *res, *p;
		char ipstr[INET6_ADDRSTRLEN];

		if(argc != 2) {
				fprintf(stderr, "usage: %s hostname\n", argv[0]);
				return 1;
		}
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;

		if((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
				fprintf(stderr, "geaddrinfo error: %s\n", gai_strerror(status));
				return 2;
		}
		printf("IP addresses for %s:\n\n", argv[1]);

		//get the pointer to the address itself
		for(p = res; p != NULL; p = p->ai_next) {
				void* addr;
				char* ipver;
				if(p->ai_family == AF_INET) {
						struct sockaddr_in* ipv4 = (struct sockaddr_in*)p->ai_addr;
						addr = &(ipv4->sin_addr);
						ipver = "IPv4";
				}else {
						struct sockaddr_in6* ipv6 = (struct sockaddr_in6*)p->ai_addr;
					    addr = &(ipv6->sin6_addr);
						ipver = "IPv6";
				}
		//convert the IP to a string and print it
		inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
		printf("\t%s: %s\n", ipver, ipstr);
		}

		freeaddrinfo(res);

		return 0;
}

