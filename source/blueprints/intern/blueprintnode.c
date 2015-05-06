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

#include "BP_blueprintnode.h"

#include <assert.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

BP_BlueprintNode *BP_blueprint_node_create()
{
	BP_BlueprintNode *bpn = (BP_BlueprintNode*)malloc(sizeof(BP_BlueprintNode));
	if (!bpn) return NULL;

	memset(bpn, 0, sizeof(*bpn));
	return bpn;
}

void BP_blueprint_node_destroy(BP_BlueprintNode *bpn)
{
	assert(bpn);
	if (!bpn) return;

	BP_BlueprintInputPort *inputp, *inputp_first = NULL;
	BLI_LISTBASE_CIRCULAR_FORWARD_BEGIN(&bpn->inputs, inputp, inputp_first);
		assert(inputp);
		BP_blueprint_input_port_destroy(inputp);
	BLI_LISTBASE_CIRCULAR_FORWARD_END(&bpn->inputs, inputp, inputp_first);

	BP_BlueprintOutputPort *outputp, *outputp_first = NULL;
	BLI_LISTBASE_CIRCULAR_FORWARD_BEGIN(&bpn->outputs, outputp, outputp_first);
		assert(outputp);
		BP_blueprint_output_port_destroy(outputp);
	BLI_LISTBASE_CIRCULAR_FORWARD_END(&bpn->outputs, outputp, outputp_first);

	free(bpn);
}
