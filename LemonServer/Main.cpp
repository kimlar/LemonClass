// WEBSOURCE: https://msdn.microsoft.com/en-us/library/windows/desktop/ms738545(v=vs.85).aspx

#include "LemonServer.h"

int main()
{
	LemonServer* server = new LemonServer();
	if (!server->Setup())
		return 1;

	std::string message = server->ReceiveMessage();

	printf("%s\n", message.c_str());
	
	server->Shutdown();

	return 0;
}
