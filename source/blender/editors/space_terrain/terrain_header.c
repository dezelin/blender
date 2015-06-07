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

/** \file blender/editors/space_terrain/terrain_header.c
*  \ingroup spterrain
*/

#include "BKE_terrain.h"

#include "BLF_translation.h"

//#include "DNA_scene_types.h"
//#include "DNA_screen_types.h"

#include "RNA_enum_types.h"

#include "UI_interface.h"
#include "UI_resources.h"


void uiTemplateHeaderTerrain(uiLayout *layout, struct bContext *C)
{
	PointerRNA v3dptr, toolsptr, sceneptr;
	uiBlock *block;
	uiLayout *row;
	int modeselect;
	
	block = uiLayoutGetBlock(layout);

	UI_block_emboss_set(block, UI_EMBOSS);
	
	modeselect = TE_MODE_BLUEPRINT;
	row = uiLayoutRow(layout, false);
	{
		EnumPropertyItem *item = terrain_mode_items;
		const char *name = "";
		int icon = ICON_TERRAIN_BLUEPRINT;

		while (item->identifier) {
			if (item->value == modeselect && item->identifier[0]) {
				name = IFACE_(item->name);
				icon = item->icon;
				break;
			}

			item++;
		}

		uiItemMenuEnumO(row, C, "TERRAIN_OT_mode_set", "mode", name, 
				icon);
	}
}

