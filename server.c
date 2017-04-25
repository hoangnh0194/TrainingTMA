#include <stdio.h>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
int sockfd, newsockfd, portno, binder, listener;
ssize_t bytes_read, bytes_written;
struct sockaddr_in serv_addr, cli_addr;
struct hostent *server;
int yes = 1;
socklen_t clilen;
char data[4096];

	if(argc < 3) {
	printf("Usage: %s ip address - port number\n", argv[0]);
	exit(EXIT_FAILURE);
	}

sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd == 0) {
	printf("SOCKET(0) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
	}

	if(sockfd < 0) {
	printf("SOCKET(-1) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
	}

		else if(sockfd) {

		  do {
		    {
		    printf("waiting for a connection.\n");
		    }
		  } while(!accept);
		}

setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

bzero(&serv_addr, sizeof(serv_addr));
server = gethostbyname(argv[1]);

	if(server == NULL) {
	fprintf(stderr, "No such host.\n");
	printf("%s\n", strerror(errno));
	exit(EXIT_FAILURE);
	}

portno = atoi(argv[2]);
serv_addr.sin_family = AF_INET;
memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
serv_addr.sin_port = htons(portno);

binder = bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

	if(binder < 0) {
	printf("BIND(-1) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
	}

listener = listen(sockfd, 20);

	if(listener < 0) {
	printf("LISTEN(-1) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
	}

clilen = sizeof(cli_addr);

newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

	if(newsockfd == 0) {
	printf("ACCEPT(0) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
	}

	if(newsockfd < 0) {
	printf("ACCEPT(-1) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
	}

	if(accept) {
	  {
	  printf("Received connection from %s.\n", inet_ntoa(cli_addr.sin_addr));
	  }
	}

for( ; ; ) {
bytes_read = read(newsockfd, data, sizeof(data));

	if(bytes_read < 0) {
	printf("READ(-1) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
	}

	if(bytes_read == 0) {
	printf("READ(0) error ---> %s.\n", strerror(errno));
	exit(EXIT_SUCCESS);
	}

	fprintf(stdout, "Client: %s", data);

printf("message: ");
fgets(data, sizeof(data), stdin);
bytes_written = write(newsockfd, data, strlen(data));

	if(bytes_written < 0) {
	printf("WRITE(-1) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
	}
}

close(newsockfd);
close(sockfd);

return 0;
}
