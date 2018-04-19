#include <iostream>
#include <thread>
#include "TcpServer.h"

using namespace std;

int main(int argc, char const *argv[])
{
	TcpServer server;
	int fd;
	if (argc == 3) 
		fd = server.connect(argv[1], atoi(argv[2]));
	else 
		fd = server.connect("127.0.0.1", 8080);

	thread t([&]() {
	server.start(fd);
	SockMessage result;
	while(1) {
		cout << "fd = " << fd << endl;
		SocketState s = server.poll(&result);
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
	 });


	while(1) {
		char* buf = new char[1024];
		cout << "input : " << endl;
		fgets(buf, 1024, stdin);
		server.write(fd, buf, strlen(buf));
		if (strncmp(buf, "exit", 4) == 0)
			break;
	}
	t.join();

	return 0;
}
