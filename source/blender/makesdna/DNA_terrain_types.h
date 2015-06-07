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
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
* The Original Code is Copyright (C) 2015 Aleksandar Dezelin.
* All rights reserved.
*
* Contributor(s): not yeat.
*
* ***** END GPL LICENSE BLOCK *****
*/

#ifndef __DNA_TERRAIN_TYPES_H__
#define __DNA_TERRAIN_TYPES_H__

#include "BLI_listbase.h"

#include "DNA_ID.h"

enum {
	TE_TYPE_BLUEPRINT = 0
};

typedef struct TerrainBlueprintVar {
	struct TerrainBlueprintVar *next, *prev;
} TerrainBlueprintVar;

typedef struct TerrainBlueprintEvent {
	struct TerrainBlueprintEvent *next, *prev;
} TerrainBlueprintEvent;

typedef struct TerrainBlueprintFunc {
	struct TerrainBlueprintFunc *next, *prev;
} TerrainBlueprintFunc;

typedef struct TerrainBlueprintInputPort {
	struct TerrainBlueprintInputPort *next, *prev;
} TerrainBlueprintInputPort;

typedef struct TerrainBlueprintOutputPort {
	struct TerrainBlueprintOutputPort *next, *prev;
} TerrainBlueprintOutputPort;

typedef struct TerrainBlueprintConn {
	struct TerrainBlueprintConn *next, *prev;
} TerrainBlueprintConn;

typedef struct TerrainBlueprintNode {
	struct TerrainBlueprintNode *next, *prev;

	/* TE_BlueprintInputPort is the base structure for this list */
	ListBase inputs;
	/* TE_BlueprintOutputPort is the base structure for this list */
	ListBase outputs;
} TerrainBlueprintNode;

typedef struct TerrainBlueprintSettings {
	int dummy;
} TerrainBlueprintSettings;

typedef struct TerrainBlueprintDescription {
	char *author;
	char *author_email;
	char *copyright;
	char *description;
	char *license;
} TerrainBlueprintDescription;

typedef struct TerrainBlueprint {
	int type;
	int pad0;
	char *name;
	TerrainBlueprintDescription *description;
	TerrainBlueprintSettings *settings;
	ListBase nodes;
	ListBase connections;
	ListBase events;
	ListBase variables;
	ListBase functions;
} TerrainBlueprint;

typedef struct Terrain {
	ID id;
	TerrainBlueprint *blueprint;
	int mode;
	int pad0;
} Terrain;

#endif /* __DNA_TERRAIN_TYPES_H__ */
