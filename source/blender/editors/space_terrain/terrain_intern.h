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

#ifndef __TERRAIN_INTERN_H__
#define __TERRAIN_INTERN_H__

struct ARegion;
struct ARegionType;
struct bContext;
struct wmWindowManager;
struct wmOperatorType;

/* terrain_buttons.c */
void terrain_buttons_register(struct ARegionType *art);

/* terrain_toolbar.c */
void terrain_tool_props_register(struct ARegionType *art);

/* common */
void add_default_keymap_handler(struct wmWindowManager *wm, struct ARegion *ar);

/*
 * Operators
 */

/* misc */
void TERRAIN_OT_mode_set(struct wmOperatorType *ot);

/* Generator devices ops  */
void TERRAIN_OT_generators_layout(struct wmOperatorType *ot);
void TERRAIN_OT_generators_constant(struct wmOperatorType *ot);
void TERRAIN_OT_generators_gradient(struct wmOperatorType *ot);
void TERRAIN_OT_generators_radial_grad(struct wmOperatorType *ot);
void TERRAIN_OT_generators_voronoi(struct wmOperatorType *ot);
void TERRAIN_OT_generators_perlin_noise(struct wmOperatorType *ot);
void TERRAIN_OT_generators_file_input(struct wmOperatorType *ot);
void TERRAIN_OT_generators_advanced_perlin(struct wmOperatorType *ot);
void TERRAIN_OT_generators_color_generator(struct wmOperatorType *ot);

#endif /* __TERRAIN_INTERN_H__ */

