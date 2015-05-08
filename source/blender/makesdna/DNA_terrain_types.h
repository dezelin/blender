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
* Contributor(s): not yeat.
*
* ***** END GPL LICENSE BLOCK *****
*/

#ifndef __DNA_TERRAIN_TYPES_H__
#define __DNA_TERRAIN_TYPES_H__

#include "BLI_listbase.h"

typedef struct TE_BlueprintVar {
	struct TE_BlueprintVar *next, *prev;
} TE_BlueprintVar;

typedef struct TE_BlueprintEvent {
	struct TE_BlueprintEvent *next, *prev;
} TE_BlueprintEvent;

typedef struct TE_BlueprintFunc {
	struct TE_BlueprintFunc *next, *prev;
} TE_BlueprintFunc;

typedef struct TE_BlueprintInputPort {
	struct TE_BlueprintInputPort *next, *prev;
} TE_BlueprintInputPort;

typedef struct TE_BlueprintOutputPort {
	struct TE_BlueprintOutputPort *next, *prev;
} TE_BlueprintOutputPort;

typedef struct TE_BlueprintConn {
	struct TE_BlueprintConn *next, *prev;
} TE_BlueprintConn;

typedef struct TE_BlueprintNode {
	struct TE_BlueprintNode *next, *prev;

	/* TE_BlueprintInputPort is the base structure for this list */
	ListBase inputs;
	/* TE_BlueprintOutputPort is the base structure for this list */
	ListBase outputs;
} TE_BlueprintNode;

typedef struct TE_BlueprintSettings {
	int dummy;
} TE_BlueprintSettings;

typedef struct TE_BlueprintDescription {
	char *author;
	char *authorEmail;
	char *copyright;
	char *description;
	char *license;
} TE_BlueprintDescription;

typedef struct TE_Blueprint {
	int type;
	char *name;
	TE_BlueprintDescription *description;
	TE_BlueprintSettings *settings;
	ListBase nodes;
	ListBase connections;
	ListBase events;
	ListBase variables;
	ListBase functions;
} TE_Blueprint;

typedef struct TE_Terrain {
	TE_Blueprint *blueprint;
} TE_Terrain;

#endif /* __DNA_TERRAIN_TYPES_H__ */
