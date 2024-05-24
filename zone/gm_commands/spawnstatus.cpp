#include "../client.h"

void command_spawnstatus(Client *c, const Seperator *sep)
{
	if (sep->IsNumber(1))
	{
		// show spawn status by spawn2 id
		zone->SpawnStatus(c, 'a', atoi(sep->arg[1]));
	}
	else if (strcmp(sep->arg[1], "help") == 0)
	{
		c->Message(CC_Default, "Usage: #spawnstatus <[a]ll (default) | [u]nspawned | [s]pawned | [d]isabled | [e]nabled | {Spawn2 ID}>");
	}
	else {
		zone->SpawnStatus(c, sep->arg[1][0]);
	}
}

