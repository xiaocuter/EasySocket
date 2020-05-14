#include<iostream>
#include"EasySocket.h"
#pragma comment(lib,"ws2_32.lib")//VS need include ws2_32.dll
#pragma warning(disable:4996)
int main() {

	using namespace SocketLib;
	using namespace std;
	//ListeningSocket lsock;
	DataSocket dsock;
	//lsock.Listen(5000);//port 5000
	//dsock = lsock.Accept();
	std::cout << "111";
	try {
		dsock.Connect(inet_addr("127.0.0.1"), 5000);
		std::cout << "222";
		char buffer[128] = "Hello server!";
		dsock.Send(buffer, strlen(buffer));
		dsock.Receive(buffer, 128);
		cout << buffer << endl;
	}
	catch (std::exception& e) {
		std::cout <<"err "<< e.what();
	}
	

	std::cin.get();
	return 0;

}