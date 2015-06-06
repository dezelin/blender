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
	//bScreen *screen = CTX_wm_screen(C);
	//ScrArea *sa = CTX_wm_area(C);
	//Scene *scene = CTX_data_scene(C);
	//ToolSettings *ts = CTX_data_tool_settings(C);
	PointerRNA v3dptr, toolsptr, sceneptr;
	//Object *ob = OBACT;
	//Object *obedit = CTX_data_edit_object(C);
	uiBlock *block;
	uiLayout *row;
	//bool is_paint = false;
	int modeselect;
	
	//RNA_pointer_create(&screen->id, &RNA_SpaceView3D, v3d, &v3dptr);
	//RNA_pointer_create(&scene->id, &RNA_ToolSettings, ts, &toolsptr);
	//RNA_pointer_create(&scene->id, &RNA_Scene, scene, &sceneptr);

	block = uiLayoutGetBlock(layout);
	//UI_block_func_handle_set(block, do_view3d_header_buttons, NULL);

	/* other buttons: */
	UI_block_emboss_set(block, UI_EMBOSS);
/*	
	if (ob) {
		modeselect = ob->mode;
		is_paint = ELEM(ob->mode, OB_MODE_SCULPT, OB_MODE_VERTEX_PAINT, OB_MODE_WEIGHT_PAINT, OB_MODE_TEXTURE_PAINT);
	}
	else {
		modeselect = OB_MODE_OBJECT;
	}
*/
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

		uiItemMenuEnumO(row, C, "TERRAIN_OT_mode_set", "mode", name, icon);
	}
/*
	uiItemR(layout, &v3dptr, "viewport_shade", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);

	if (obedit == NULL && is_paint) {
		if (ob->mode & OB_MODE_ALL_PAINT) {
			row = uiLayoutRow(layout, true);
			uiItemR(row, &v3dptr, "pivot_point", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);
		}

		if (!ELEM(ob->mode, OB_MODE_SCULPT, OB_MODE_PARTICLE_EDIT)) {
			PointerRNA meshptr;

			RNA_pointer_create(ob->data, &RNA_Mesh, ob->data, &meshptr);
			if (ob->mode & (OB_MODE_TEXTURE_PAINT | OB_MODE_VERTEX_PAINT)) {
				uiItemR(layout, &meshptr, "use_paint_mask", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);
			}
			else {
				row = uiLayoutRow(layout, true);
				uiItemR(row, &meshptr, "use_paint_mask", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);
				uiItemR(row, &meshptr, "use_paint_mask_vertex", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);
			}
		}
	}
	else {
		row = uiLayoutRow(layout, true);
		uiItemR(row, &v3dptr, "pivot_point", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);

		if (obedit == NULL) {
			uiItemR(row, &v3dptr, "use_pivot_point_align", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);
		}

		row = uiLayoutRow(layout, true);
		uiItemR(row, &v3dptr, "show_manipulator", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);
		if (v3d->twflag & V3D_USE_MANIPULATOR) {
			uiItemR(row, &v3dptr, "transform_manipulators", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);
		}
		uiItemR(row, &v3dptr, "transform_orientation", 0, "", ICON_NONE);
	}

	if (obedit == NULL && v3d->localvd == NULL) {
		unsigned int ob_lay = ob ? ob->lay : 0;

		uiTemplateLayers(layout, v3d->scenelock ? &sceneptr : &v3dptr, "layers", &v3dptr, "layers_used", ob_lay);

		uiItemR(layout, &v3dptr, "lock_camera_and_layers", UI_ITEM_R_ICON_ONLY, "", ICON_NONE);
	}
	
	uiTemplateEditModeSelection(layout, C);
*/
}
