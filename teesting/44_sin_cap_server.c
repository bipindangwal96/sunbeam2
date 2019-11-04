#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define SERVER_IP	"127.0.0.1"
#define SERVER_PORT	2809

void strupr(char *s)
{
	while(*s != '\0')
	{
		if(islower(*s))
			*s = *s - 32;
		s++;
	}
}

int srv_fd;

void sigint_handler(int sig)
{
	//13. shutdown listening socket
	shutdown(srv_fd, SHUT_RDWR);
	printf("server socket shutdown.\n");
	_exit(0);
}

int main()
{
	char msg[64];
	int cli_fd;
	struct sockaddr_in srv_addr, cli_addr;
	socklen_t len = sizeof(srv_addr);
	struct sigaction sa;

	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigint_handler;
	sigaction(SIGINT, &sa, NULL);
	
	//1. create server socket
	srv_fd = socket(AF_INET, SOCK_STREAM, 0);
	printf("server socket created.\n");

	//2. assign address to server socket
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_IP, &srv_addr.sin_addr);
	bind(srv_fd, (struct sockaddr*)&srv_addr, len);
	printf("address given to server socket.\n");

	//3. listen to server socket
	listen(srv_fd, 5);
	printf("listening to server socket.\n");

	while(1)
	{
		//6. accept client connection
		printf("waiting for client connection.\n");
		cli_fd = accept(srv_fd, (struct sockaddr*)&cli_addr, &len);
		printf("client connection connection accepted.\n");

		//8. read data from client & display
		read(cli_fd, msg, sizeof(msg));
		printf("client: %s\n", msg);

		//9. write data to client
		strupr(msg);
		write(cli_fd, msg, strlen(msg)+1);

		//12. close socket
		close(cli_fd);
	}

	return 0;	
}

