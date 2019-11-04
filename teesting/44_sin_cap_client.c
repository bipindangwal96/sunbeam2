#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define SERVER_IP	"127.0.0.1"
#define SERVER_PORT	2809

int main(int argc, char *argv[])
{
	char msg[64];
	int cli_fd;
	struct sockaddr_in srv_addr;
	socklen_t len = sizeof(srv_addr);

	if(argc != 2)
	{
		fprintf(stderr, "invalid args.\n");
		_exit(1);
	}

	//4. create client socket
	cli_fd = socket(AF_INET, SOCK_STREAM, 0);
	printf("client socket created.\n");

	//5. connect to server socket
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_IP, &srv_addr.sin_addr);
	connect(cli_fd, (struct sockaddr*)&srv_addr, len);
	printf("connected to server socket.\n");

	//7. send data to server
	write(cli_fd, argv[1], strlen(argv[1])+1);

	//10. read data from server & display
	read(cli_fd, msg, sizeof(msg));
	printf("server: %s\n", msg);

	//11. close client socket
	close(cli_fd);

	printf("client socket created.\n");
	return 0;
}

