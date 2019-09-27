// WEBSOURCE: https://msdn.microsoft.com/en-us/library/windows/desktop/ms738545(v=vs.85).aspx

#include "LemonClient.h"

int main()
{
	LemonClient* client = new LemonClient("127.0.0.1");

	if (!client->Connect())
		return -1;

	if (!client->SendMessage("Hello world!"))
		return -1;

	std::string gotMessage = client->ReceivedMessage();

	printf("%s\n", gotMessage.c_str());

	client->Disconnect();

	return 0;
}
