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

#include "MEM_guardedalloc.h"

#include "DNA_terrain_types.h"

#include "BKE_library.h"
#include "BKE_terrain.h"


void BKE_terrain_free(struct Terrain *terrain)
{
	
}

void BKE_terrain_unlink(struct Terrain *terrain)
{

}

struct Terrain *BKE_terrain_add(struct Main *bmain, const char *name)
{
	Terrain *tr;

	tr = BKE_libblock_alloc(bmain, ID_TRN, name);
	return tr;
}

struct Terrain *BKE_terrain_copy(struct Terrain *terrain)
{
	Terrain *tr;

	tr = BKE_libblock_copy(&terrain->id);
	return 0;
}
