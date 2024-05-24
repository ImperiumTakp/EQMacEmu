#include "../client.h"
#include "../worldserver.h"
extern WorldServer worldserver;

void command_emote(Client *c, const Seperator *sep){
	if (sep->arg[3][0] == 0)
		c->Message(CC_Default, "Usage: #emote [name | world | zone] type# message");
	else {
		if (strcasecmp(sep->arg[1], "zone") == 0){
			char* newmessage = 0;
			if (strstr(sep->arg[3], "^") == 0)
				entity_list.Message(CC_Default, atoi(sep->arg[2]), sep->argplus[3]);
			else{
				for (newmessage = strtok((char*)sep->arg[3], "^"); newmessage != nullptr; newmessage = strtok(nullptr, "^"))
					entity_list.Message(CC_Default, atoi(sep->arg[2]), newmessage);
			}
		}
		else if (!worldserver.Connected())
			c->Message(CC_Default, "Error: World server disconnected");
		else if (strcasecmp(sep->arg[1], "world") == 0)
			worldserver.SendEmoteMessage(0, 0, atoi(sep->arg[2]), sep->argplus[3]);
		else
			worldserver.SendEmoteMessage(sep->arg[1], 0, atoi(sep->arg[2]), sep->argplus[3]);
	}
}

