#include <iostream>
#include <string.h>
#include <WinSock2.h>
#include "FutsuKoma.h"

using namespace std;

#pragma warning(disable:4996)

void func()
{
	WSADATA wsaData;
	struct sockaddr_in server;
	SOCKET sock;
	char buf[32];
	char deststr[32];

	strcpy(deststr, "10.25.222.212");

	WSAStartup(MAKEWORD(2, 0), &wsaData);

	sock = socket(AF_INET, SOCK_STREAM, 0);

	server.sin_family = AF_INET;
	server.sin_port = htons(50010);

	server.sin_addr.S_un.S_addr = inet_addr(deststr);
	if (server.sin_addr.S_un.S_addr == 0xffffffff) {
		struct hostent* host;

		host = gethostbyname(deststr);
		if (host == NULL) {
			return;
		}
		server.sin_addr.S_un.S_addr =
			*(unsigned int*)host->h_addr_list[0];
	}

	connect(sock, (struct sockaddr*) & server, sizeof(server));

	send(sock, "Hello", 5, 0);

	memset(buf, 0, sizeof(buf));

	int n = recv(sock, buf, sizeof(buf), 0);

	std::cout << buf << std::endl;

	closesocket(sock);

	WSACleanup();

}

int main(void)
{
	const int mOU = 1;
	const int mKI = 2;
	const int mGI = 3;
	const int mKE = 4;
	const int mKY = 5;
	const int mHI = 6;
	const int mKA = 7;
	const int mFU = 8;
	const int mNK = 9;
	const int mRY = 10;
	const int mUM = 11;
	const int mTO = 12;

	const int eOU = 17;
	const int eKI = 18;
	const int eGI = 19;
	const int eKE = 20;
	const int eKY = 21;
	const int eHI = 22;
	const int eKA = 23;
	const int eFU = 24;
	const int eNK = 25;
	const int eRY = 26;
	const int eUM = 27;
	const int eTO = 28;

	int board[81];

	FutsuKoma *futsukoma = new FutsuKoma(mOU);

	std::vector<int> pattern = futsukoma->getMovablePattern(mOU);
	std::vector<int> movable = futsukoma->getMovablePos(mOU, 77, pattern, &board[0]);

	for (int i = 0; i < movable.size(); i++)
		std::cout << movable.at(i) << std::endl;

	func();

	int s;

	cin >> s;

	delete(futsukoma);


	return 0;
}