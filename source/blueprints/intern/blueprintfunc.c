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

#include "BP_blueprintfunc.h"

#include <malloc.h>
#include <memory.h>
#include <string.h>

BP_BlueprintFunc *BP_blueprint_func_create(void *ctx)
{
	BP_BlueprintFunc *bpf = (BP_BlueprintFunc*)malloc(sizeof(BP_BlueprintFunc));
	if (!bpf) return NULL;

	memset(bpf, 0, sizeof(*bpf));
	bpf->ctx = ctx;
	return bpf;
}

void BP_blueprint_func_destroy(BP_BlueprintFunc *bpf)
{
	free(bpf);
}
