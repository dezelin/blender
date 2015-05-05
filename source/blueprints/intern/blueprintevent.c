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

#include "BP_blueprintevent.h"

#include <malloc.h>
#include <memory.h>
#include <string.h>

BP_BlueprintEvent *BP_blueprint_event_create(void *ctx)
{
	BP_BlueprintEvent *bpe = (BP_BlueprintEvent*)malloc(sizeof(BP_BlueprintEvent));
	if (!bpe) return NULL;

	memset(bpe, 0, sizeof(*bpe));
	bpe->ctx = ctx;
	return bpe;
}

void BP_blueprint_event_destroy(BP_BlueprintEvent *bpe)
{
	free(bpe);
}
