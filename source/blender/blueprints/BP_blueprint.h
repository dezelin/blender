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

#ifndef __BP_BLUEPRINT_H__
#define __BP_BLUEPRINT_H__

#include "BLI_listbase.h"
#include "BP_blueprintsettings.h"
#include "BP_blueprintdescription.h"

typedef struct BP_Blueprint {
	int type;
	char *name;
	BP_BlueprintDescription *description;
	BP_BlueprintSettings *settings;
	ListBase nodes;
	ListBase connections;
	ListBase events;
	ListBase variables;
	ListBase functions;
} BP_Blueprint;

BP_Blueprint *BP_blueprint_create(int type, const char *name);

void BP_blueprint_set_description(BP_Blueprint *bp, 
	BP_BlueprintDescription *description);

void BP_blueprint_set_settings(BP_Blueprint *bp, BP_BlueprintSettings *settings);

void BP_blueprint_destroy(BP_Blueprint *bp);

#endif /* __BP_BLUEPRINT_H__ */
