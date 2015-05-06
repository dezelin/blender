/*
* ***** BEGIN GPL LICENSE BLOCK *****
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
* The Original Code is Copyright (C) 2015 Aleksandar Dezelin.
* All rights reserved.
*
* The Original Code is: all of this file.
*
* Contributor(s): none yet.
*
* ***** END GPL LICENSE BLOCK *****
*/

#include "BP_blueprint.h"
#include "BP_blueprintconn.h"
#include "BP_blueprintevent.h"
#include "BP_blueprintfunc.h"
#include "BP_blueprintnode.h"

#include <assert.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

BP_Blueprint *BP_blueprint_create(int type, const char *name)
{
	assert(name);
	if (!name) return NULL;

	BP_Blueprint *bp = (BP_Blueprint*)malloc(sizeof(BP_Blueprint));
	if (!bp) return NULL;

	memset(bp, 0, sizeof(*bp));
	bp->type = type;
	bp->name = _strdup(name);
	return bp;
}

void BP_blueprint_set_description(BP_Blueprint *bp, 
	BP_BlueprintDescription *description)
{
	assert(bp);
	assert(description);
	if (!bp || !description) return;
	bp->description = (BP_BlueprintDescription*)description;
}

void BP_blueprint_set_settings(BP_Blueprint *bp, BP_BlueprintSettings *settings)
{
	assert(bp);
	assert(settings);
	if (!bp || !settings) return;
	bp->settings = (BP_BlueprintSettings*)settings;
}

void BP_blueprint_destroy(BP_Blueprint *bp)
{
	assert(bp);
	if (!bp) return;
	if (bp->name) free(bp->name);
	if (bp->description) free(bp->description);
	if (bp->settings) free(bp->settings);

	BP_BlueprintNode *node, *node_first = NULL;
	BLI_LISTBASE_CIRCULAR_FORWARD_BEGIN(&bp->nodes, node, node_first);
		free(node);
	BLI_LISTBASE_CIRCULAR_FORWARD_END(&bp->nodes, node, node_first);

	BP_BlueprintConn *conn, *conn_first = NULL;
	BLI_LISTBASE_CIRCULAR_FORWARD_BEGIN(&bp->connections, conn, conn_first);
		free(conn);
	BLI_LISTBASE_CIRCULAR_FORWARD_END(&bp->connections, conn, conn_first);

	BP_BlueprintEvent *event, *event_first = NULL;
	BLI_LISTBASE_CIRCULAR_FORWARD_BEGIN(&bp->events, event, event_first);
		free(event);
	BLI_LISTBASE_CIRCULAR_FORWARD_END(&bp->events, event, event_first);

	BP_BlueprintFunc *func, *func_first = NULL;
	BLI_LISTBASE_CIRCULAR_FORWARD_BEGIN(&bp->functions, func, func_first);
		free(func);
	BLI_LISTBASE_CIRCULAR_FORWARD_END(&bp->functions, func, func_first);

	free(bp);
}
