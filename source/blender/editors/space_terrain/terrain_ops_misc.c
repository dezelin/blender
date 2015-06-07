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
* The Original Code is: all of this file.
*
* Contributor(s): none yet.
*
* ***** END GPL LICENSE BLOCK *****
*/

#include "BKE_context.h"
#include "BKE_terrain.h"

#include "DNA_terrain_types.h"
#include "DNA_windowmanager_types.h"

#include "ED_screen.h"

#include "RNA_access.h"
#include "RNA_define.h"
#include "RNA_enum_types.h"
#include "RNA_types.h"

#include "WM_types.h"

#include "terrain_intern.h"


static int terrain_mode_set_exec(bContext *C, wmOperator *op)
{
	return 0;
}

static EnumPropertyItem *terrain_mode_set_itemsf(bContext *C, 
		PointerRNA *UNUSED(ptr), PropertyRNA *UNUSED(prop), 
		bool *r_free)
{
	EnumPropertyItem *input = terrain_mode_items;
	EnumPropertyItem *item = NULL;
	Terrain *terrain;
	int totitem = 0;

	if (!C) /* needed for docs */
		return terrain_mode_items;

	while (input->identifier) {
		RNA_enum_item_add(&item, &totitem, input);
		input++;
	}

	RNA_enum_item_end(&item, &totitem);

	*r_free = true;

	return item;
}

void TERRAIN_OT_mode_set(wmOperatorType *ot)
{
	PropertyRNA *prop;
	
	/* identifiers */
	ot->name = "Set Terrain Mode";
	ot->description = "Sets the terrain interaction mode";
	ot->idname = "TERRAIN_OT_mode_set";
	
	/* api callbacks */
	ot->exec = terrain_mode_set_exec;
	
	ot->poll = ED_operator_terrain_active;
	
	/* flags */
	ot->flag = 0; /* no register/undo here, leave it to operators being called */
	
	ot->prop = RNA_def_enum(ot->srna, "mode", terrain_mode_items, 
			TE_MODE_BLUEPRINT, "Mode", "");
	RNA_def_enum_funcs(ot->prop, terrain_mode_set_itemsf);
	RNA_def_property_flag(ot->prop, PROP_SKIP_SAVE);

	prop = RNA_def_boolean(ot->srna, "toggle", 0, "Toggle", "");
	RNA_def_property_flag(prop, PROP_SKIP_SAVE);
}

