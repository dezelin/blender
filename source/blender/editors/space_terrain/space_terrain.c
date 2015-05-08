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

/** \file blender/editors/space_terrain/space_terrain.c
*  \ingroup spterrain
*/

#include <string.h>

#include "DNA_terrain_types.h"

#include "MEM_guardedalloc.h"

#include "BLI_blenlib.h"

#include "BKE_context.h"
#include "BKE_screen.h"

#include "ED_space_api.h"
#include "ED_screen.h"

#include "BIF_gl.h"

#include "WM_api.h"
#include "WM_types.h"

#include "UI_interface.h"
#include "UI_resources.h"
#include "UI_view2d.h"

#include "terrain_intern.h"


static SpaceLink *terrain_new(const bContext *C)
{
	ARegion *ar;
	SpaceTerrain *sterrain;

	sterrain = MEM_callocN(sizeof(SpaceTerrain), "initterrain");
	sterrain->spacetype = SPACE_TERRAIN;

	/* header */
	ar = MEM_callocN(sizeof(ARegion), "header for terrain");
	BLI_addtail(&sterrain->regionbase, ar);
	ar->regiontype = RGN_TYPE_HEADER;
	ar->alignment = RGN_ALIGN_BOTTOM;

	/* toolshelf */
	ar = MEM_callocN(sizeof(ARegion), "toolshelf for terrain");
	BLI_addtail(&sterrain->regionbase, ar);
	ar->regiontype = RGN_TYPE_TOOLS;
	ar->alignment = RGN_ALIGN_LEFT;
	ar->flag = RGN_FLAG_HIDDEN;

	/* tool properties */
	ar = MEM_callocN(sizeof(ARegion), "tool properties for terrain");
	BLI_addtail(&sterrain->regionbase, ar);
	ar->regiontype = RGN_TYPE_TOOL_PROPS;
	ar->alignment = RGN_ALIGN_BOTTOM | RGN_SPLIT_PREV;
	ar->flag = RGN_FLAG_HIDDEN;

	/* buttons/list view */
	ar = MEM_callocN(sizeof(ARegion), "buttons for terrain");
	BLI_addtail(&sterrain->regionbase, ar);
	ar->regiontype = RGN_TYPE_UI;
	ar->alignment = RGN_ALIGN_RIGHT;
	ar->flag = RGN_FLAG_HIDDEN;
	
	/* main area */
	ar = MEM_callocN(sizeof(ARegion), "main area for terrain");
	BLI_addtail(&sterrain->regionbase, ar);
	ar->regiontype = RGN_TYPE_WINDOW;
	ar->regiondata = MEM_callocN(sizeof(TE_Terrain), "terrain and blueprint data");

	return (SpaceLink *)sterrain;
}

static void terrain_free(SpaceLink *sl)
{

}

static void terrain_init(wmWindowManager *UNUSED(wm), ScrArea *UNUSED(sa))
{
}

static void terrain_listener(bScreen *UNUSED(sc), ScrArea *sa, struct wmNotifier *wmn)
{
}

static SpaceLink *terrain_duplicate(SpaceLink *sl)
{
	return NULL;
}

void terrain_operatortypes(void)
{

}

void terrain_keymap(wmKeyConfig *keyconf)
{

}

static void terrain_dropboxes(void)
{

}

static int terrain_context(const bContext *C, const char *member, bContextDataResult *result)
{
	return 0;
}

static void terrain_main_area_draw(const bContext *C, ARegion *ar)
{
	/* draw entirely, view changes should be handled here */
	SpaceTerrain *sterrain = CTX_wm_space_terrain(C);
	View2D *v2d = &ar->v2d;
	View2DScrollers *scrollers;

	/* clear and setup matrix */
	UI_ThemeClearColor(TH_BACK);
	glClear(GL_COLOR_BUFFER_BIT);

	/* works best with no view2d matrix set */
	UI_view2d_view_ortho(v2d);

	/* reset view matrix */
	UI_view2d_view_restore(C);

	/* scrollers */
	scrollers = UI_view2d_scrollers_calc(C, v2d, V2D_ARG_DUMMY, V2D_ARG_DUMMY, V2D_ARG_DUMMY, V2D_GRID_CLAMP);
	UI_view2d_scrollers_draw(C, v2d, scrollers);
	UI_view2d_scrollers_free(scrollers);
}

/* add handlers, stuff you only do once or on area/region changes */
static void terrain_main_area_init(wmWindowManager *wm, ARegion *ar)
{
	add_default_keymap_handler(wm, ar);
	UI_view2d_region_reinit(&ar->v2d, V2D_COMMONVIEW_CUSTOM, ar->winx, ar->winy);
}

static void terrain_main_area_exit(wmWindowManager *wm, ARegion *ar)
{

}

static void terrain_main_area_free(ARegion *ar)
{

}

/* copy regiondata */
static void *terrain_main_area_duplicate(void *poin)
{
	return NULL;
}

static void terrain_main_area_listener(bScreen *sc, ScrArea *sa, ARegion *ar, wmNotifier *wmn)
{

}

static void terrain_main_area_cursor(wmWindow *win, ScrArea *UNUSED(sa), ARegion *UNUSED(ar))
{

}

static void terrain_buttons_area_listener(bScreen *UNUSED(sc), ScrArea *UNUSED(sa), ARegion *ar, wmNotifier *wmn)
{

}

/* add handlers, stuff you only do once or on area/region changes */
static void terrain_buttons_area_init(wmWindowManager *wm, ARegion *ar)
{
	add_default_keymap_handler(wm, ar);
}

static void terrain_buttons_area_draw(const bContext *C, ARegion *ar)
{

}

static void terrain_tools_area_listener(bScreen *UNUSED(sc), ScrArea *UNUSED(sa), ARegion *ar, wmNotifier *wmn)
{

}

static void terrain_tools_area_init(wmWindowManager *wm, ARegion *ar)
{
	add_default_keymap_handler(wm, ar);
}

static void terrain_tools_area_draw(const bContext *C, ARegion *ar)
{

}

static void terrain_props_area_listener(bScreen *UNUSED(sc), ScrArea *UNUSED(sa), ARegion *ar, wmNotifier *wmn)
{

}

static void terrain_props_area_init(wmWindowManager *wm, ARegion *ar)
{
	add_default_keymap_handler(wm, ar);
}

static void terrain_props_area_draw(const bContext *C, ARegion *ar)
{

}

static void terrain_header_area_listener(bScreen *UNUSED(sc), ScrArea *UNUSED(sa), ARegion *ar, wmNotifier *wmn)
{

}

static void terrain_header_area_init(wmWindowManager *wm, ARegion *ar)
{
	add_default_keymap_handler(wm, ar);
	ED_region_header_init(ar);
}

static void terrain_header_area_draw(const bContext *C, ARegion *ar)
{
	ED_region_header(C, ar);
}

void ED_spacetype_terrain()
{
	SpaceType *st = MEM_callocN(sizeof(SpaceType), "spacetype terrain");
	ARegionType *art;

	st->spaceid = SPACE_TERRAIN;
	strncpy(st->name, "Terrain", BKE_ST_MAXNAME);

	st->new = terrain_new;
	st->free = terrain_free;
	st->init = terrain_init;
	st->listener = terrain_listener;
	st->duplicate = terrain_duplicate;
	st->operatortypes = terrain_operatortypes;
	st->keymap = terrain_keymap;
	st->dropboxes = terrain_dropboxes;
	st->context = terrain_context;

	/* regions: main window */
	art = MEM_callocN(sizeof(ARegionType), "spacetype terrain region");
	art->regionid = RGN_TYPE_WINDOW;
	art->keymapflag = ED_KEYMAP_VIEW2D;
	art->draw = terrain_main_area_draw;
	art->init = terrain_main_area_init;
	art->exit = terrain_main_area_exit;
	art->free = terrain_main_area_free;
	art->duplicate = terrain_main_area_duplicate;
	art->listener = terrain_main_area_listener;
	art->cursor = terrain_main_area_cursor;
	art->lock = 1; /* can become flag, see BKE_spacedata_draw_locks */
	BLI_addhead(&st->regiontypes, art);

	/* regions: listview/buttons */
	art = MEM_callocN(sizeof(ARegionType), "spacetype terrain buttons region");
	art->regionid = RGN_TYPE_UI;
	art->prefsizex = 180; /* XXX */
	art->keymapflag = ED_KEYMAP_UI | ED_KEYMAP_FRAMES;
	art->listener = terrain_buttons_area_listener;
	art->init = terrain_buttons_area_init;
	art->draw = terrain_buttons_area_draw;
	BLI_addhead(&st->regiontypes, art);

	terrain_buttons_register(art);

	/* regions: tool(bar) */
	art = MEM_callocN(sizeof(ARegionType), "spacetype terrain tools region");
	art->regionid = RGN_TYPE_TOOLS;
	art->prefsizex = 160; /* XXX */
	art->prefsizey = 50; /* XXX */
	art->keymapflag = ED_KEYMAP_UI | ED_KEYMAP_FRAMES;
	art->listener = terrain_tools_area_listener;
	art->init = terrain_tools_area_init;
	art->draw = terrain_tools_area_draw;
	BLI_addhead(&st->regiontypes, art);

	/* regions: tool properties */
	art = MEM_callocN(sizeof(ARegionType), "spacetype terrain tool properties region");
	art->regionid = RGN_TYPE_TOOL_PROPS;
	art->prefsizex = 0;
	art->prefsizey = 120;
	art->keymapflag = ED_KEYMAP_UI | ED_KEYMAP_FRAMES;
	art->listener = terrain_props_area_listener;
	art->init = terrain_props_area_init;
	art->draw = terrain_props_area_draw;
	BLI_addhead(&st->regiontypes, art);

	terrain_tool_props_register(art);

	/* regions: header */
	art = MEM_callocN(sizeof(ARegionType), "spacetype terrain header region");
	art->regionid = RGN_TYPE_HEADER;
	art->prefsizey = HEADERY;
	art->keymapflag = ED_KEYMAP_UI | ED_KEYMAP_VIEW2D | ED_KEYMAP_FRAMES | ED_KEYMAP_HEADER;
	art->listener = terrain_header_area_listener;
	art->init = terrain_header_area_init;
	art->draw = terrain_header_area_draw;
	BLI_addhead(&st->regiontypes, art);

	BKE_spacetype_register(st);
}