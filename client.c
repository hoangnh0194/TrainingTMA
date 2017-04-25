#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char *argv[]) {
int sockfd, portno, connector, yes = 1;
ssize_t bytes_read, bytes_written;
struct hostent *server;
struct sockaddr_in serv_addr, cli_addr;
char buffer[4096];

	if(argc < 3)
	{
	fprintf(stderr, "Ussage: %s + IP Address + port No.\n", argv[0]);
	exit(0);
	}

sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
	printf("SOCKET(-1) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
	}

	if(sockfd == 0) {
	printf("SOCKET(0) error ---> %s.\n", strerror(errno));
	exit(EXIT_FAILURE);
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

	connector = connect(sockfd, (const struct sockaddr *) &serv_addr, sizeof(serv_addr));
        if(connector < 0) {
	fprintf(stderr, "%s. CONNECT()\n", strerror(errno));
	exit(EXIT_FAILURE);
	}
		else {
		printf("Made a connection to %s\n", inet_ntoa(serv_addr.sin_addr));
		}

for( ; ; )
{

printf("Message: ");
fgets(buffer, sizeof(buffer), stdin);
bytes_written = write(sockfd, buffer, sizeof(buffer));
	if(bytes_written == 0) {
	printf("WRITE(0) error ---> %s.\n", strerror(errno));
	printf("Nothing was written.\n");
	break;
	}

memset(buffer, 0, sizeof(buffer));
bytes_read = read(sockfd, buffer, sizeof(buffer));
	if(bytes_read < 0) {
        //fprintf(stderr, "Error reading message from %s\n", inet_ntoa(cli_addr.sin_addr));
        printf("READ(c) error ---> %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
        }

	//Test to see if the buffer is blank.
        if(bytes_read == 0) {
        printf("READ(0) error ---> %s.\n", strerror(errno));
	exit(EXIT_SUCCESS);
        }

	fprintf(stdout, "server: %s", buffer);

}

close(sockfd);

return 0;
}
