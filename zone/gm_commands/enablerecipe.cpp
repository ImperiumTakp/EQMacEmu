#include "../client.h"

void command_enablerecipe(Client *c, const Seperator *sep){
	uint32 recipe_id = 0;
	bool success = false;
	if (c) {
		if (sep->argnum == 1) {
			recipe_id = atoi(sep->arg[1]);
		}
		else {
			c->Message(CC_Default, "Invalid number of arguments.\nUsage: #enablerecipe recipe_id");
			return;
		}
		if (recipe_id > 0) {
			success = database.EnableRecipe(recipe_id);
			if (success) {
				c->Message(CC_Default, "Recipe enabled.");
			}
			else {
				c->Message(CC_Default, "Recipe not enabled.");
			}
		}
		else {
			c->Message(CC_Default, "Invalid recipe id.\nUsage: #enablerecipe recipe_id");
		}
	}
}
