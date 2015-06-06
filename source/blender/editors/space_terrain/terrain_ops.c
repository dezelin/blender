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

#include "MEM_guardedalloc.h"

#include "DNA_windowmanager_types.h"

#include "WM_api.h"

#include "terrain_intern.h"


void ED_operatortypes_terrain()
{
    /* Generator devices ops */
    WM_operatortype_append(TERRAIN_OT_generators_layout);
    WM_operatortype_append(TERRAIN_OT_generators_constant);
    WM_operatortype_append(TERRAIN_OT_generators_gradient);
    WM_operatortype_append(TERRAIN_OT_generators_radial_grad);
    WM_operatortype_append(TERRAIN_OT_generators_voronoi);
    WM_operatortype_append(TERRAIN_OT_generators_perlin_noise);
    WM_operatortype_append(TERRAIN_OT_generators_file_input);
    WM_operatortype_append(TERRAIN_OT_generators_advanced_perlin);
    WM_operatortype_append(TERRAIN_OT_generators_color_generator);

}

void ED_operatormacros_terrain()
{
}

void ED_keymap_terrain(wmKeyConfig *keyconf)
{
}


