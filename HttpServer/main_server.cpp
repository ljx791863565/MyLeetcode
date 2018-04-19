#include <iostream>

#include "TcpServer.h"
using namespace std;

int main(int argc, char* argv[])
{
	TcpServer server;
	int fd;
	if (argc == 3)
		fd = server.listen(argv[1], atoi(argv[2]));
	else 
		fd = server.listen("127.0.0.1", 8080);

	server.start(fd);
	SockMessage result;
	while(1) {
		SocketState s = server.poll(&result);
		cout << "fd = " << fd << endl;
		cout << "state = " << s << endl;
		switch(s) {
			case kData : 
				cout << "new data : " << result.data << endl;
				if (strncmp(result.data, "exit", 4) == 0) {
					server.exit();
				}
				server.write(result.fd, result.data, result.ud);
				break;
			case kClose :
				cout << "close " << result.fd << endl;
				break;
			case kOpen :
				cout << "open " << result.fd << endl;
				break;
			case kAccept :
				cout << "new connect " << result.ud << endl;
				server.start(result.ud);
				break;
			case kError :
				cout << "error " << endl;
				break;
			case kExit : 
				cout << "exit " << endl;
				goto label;
			default:
				break;

		}
	}
label:
	cout << "down!" << endl;
	return 0;
}