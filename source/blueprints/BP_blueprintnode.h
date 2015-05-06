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

#ifndef __BP_BLUEPRINTNODE_H__
#define __BP_BLUEPRINTNODE_H__

#include "BLI_listbase.h"

#include "BP_blueprintinputport.h"
#include "BP_blueprintoutputport.h"

typedef struct BP_BlueprintNode {
	struct BP_BlueprintNode *next, *prev;
	void *ctx;

	/* BP_BlueprintInputPort is the base structure for this list */
	ListBase inputs;
	/* BP_BlueprintOutputPort is the base structure for this list */
	ListBase outputs;

} BP_BlueprintNode;

BP_BlueprintNode *BP_blueprint_node_create();

void BP_blueprint_node_destroy(BP_BlueprintNode *bpn);

#endif /* __BP_BLUEPRINTNODE_H__ */
