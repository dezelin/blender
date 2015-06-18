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
* The Original Code is Copyright (C) 2015 Aleksandar Dezelin
* All rights reserved.
*
*
* Contributor(s): none yet.
*
* ***** END GPL LICENSE BLOCK *****
*/

/** \file blender/editors/space_terrain/terrain_draw.c
*  \ingroup spterrain
*/

#include "BKE_context.h"
#include "BKE_screen.h"

#include "BLI_listbase.h"

#include "DNA_screen_types.h"
#include "DNA_space_types.h"
#include "DNA_terrain_types.h"

#include <assert.h>

static void blueprint_draw(TerrainBlueprint *bp, ARegion *ar)
{
}

void terrain_draw_current(const bContext *C, ARegion *ar)
{
    TerrainBlueprint *bp;
    SpaceTerrain *space = CTX_wm_space_terrain(C);
    Terrain *tr = space->terrain;
    if (!tr)
        return;

    bp = (TerrainBlueprint *)BLI_findlink(&tr->blueprints, 
            tr->curr);
    if (!bp)
        return;

    blueprint_draw(bp, ar);   
}

