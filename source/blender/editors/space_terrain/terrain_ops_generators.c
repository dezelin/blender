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

#include "BLF_translation.h"

#include "BKE_context.h"
#include "BKE_terrain.h"

#include "DNA_terrain_types.h"
#include "DNA_windowmanager_types.h"

#include "ED_screen.h"
#include "ED_terrain.h"

#include "MEM_guardedalloc.h"

#include "WM_api.h"
#include "WM_types.h"

#include "terrain_intern.h"


static int generators_layout_invoke(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
    ED_area_headerprint(CTX_wm_area(C), IFACE_("Use LMB click to define location where place the device"));

    /* add modal handler for ESC */
    WM_event_add_modal_handler(C, op);

	return OPERATOR_RUNNING_MODAL;
}

static int generators_layout_modal(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
    SpaceTerrain *space = CTX_wm_space_terrain(C);
    Terrain *tr = ED_space_terrain_get_terrain(space);
    ARegion *ar = CTX_wm_region(C);

    switch (event->type) {
        case MOUSEMOVE:
            return OPERATOR_RUNNING_MODAL;

        case LEFTMOUSE:
            ED_area_headerprint(CTX_wm_area(C), NULL);
            WM_event_add_notifier(C, NC_TERRAIN | NA_EDITED, tr);
            return OPERATOR_FINISHED;

        case ESCKEY:
            ED_area_headerprint(CTX_wm_area(C), NULL);
            return OPERATOR_CANCELLED;
    }

	return OPERATOR_PASS_THROUGH;
}

static int generators_layout_poll(struct bContext *C)
{
	return ED_operator_terrain_active(C);
}

void TERRAIN_OT_generators_layout(wmOperatorType *ot)
{
	/* identifiers */
	ot->name = "Layout";
	ot->description = "Layout generator";
	ot->idname = "TERRAIN_OT_generators_layout";

	/* api callbacks */
	ot->invoke = generators_layout_invoke;
	ot->modal = generators_layout_modal;
	ot->poll = generators_layout_poll;

	/* flags */
	ot->flag = OPTYPE_REGISTER | OPTYPE_UNDO | OPTYPE_BLOCKING;
}

static int generators_constant_invoke(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_constant_exec(bContext *C, wmOperator *op)
{
	return 0;
}

static int generators_constant_modal(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_constant_poll(struct bContext *C)
{
	return ED_operator_terrain_active(C);
}

static void generators_constant_cancel(bContext *C, wmOperator *op)
{
}

void TERRAIN_OT_generators_constant(wmOperatorType *ot)
{
	/* identifiers */
	ot->name = "Constant";
	ot->description = "Constant generator";
	ot->idname = "TERRAIN_OT_generators_constant";

	/* api callbacks */
	ot->invoke = generators_constant_invoke;
	ot->modal = generators_constant_modal;
	ot->poll = generators_constant_poll;
	ot->cancel = generators_constant_cancel;

	/* flags */
	ot->flag = OPTYPE_BLOCKING | OPTYPE_GRAB_CURSOR;
}

static int generators_gradient_invoke(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_gradient_exec(bContext *C, wmOperator *op)
{
	return 0;
}

static int generators_gradient_modal(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_gradient_poll(struct bContext *C)
{
	return ED_operator_terrain_active(C);
}

static void generators_gradient_cancel(bContext *C, wmOperator *op)
{
}

void TERRAIN_OT_generators_gradient(wmOperatorType *ot)
{
	/* identifiers */
	ot->name = "Gradient";
	ot->description = "Gradient generator";
	ot->idname = "TERRAIN_OT_generators_gradient";

	/* api callbacks */
	ot->invoke = generators_gradient_invoke;
	ot->modal = generators_gradient_modal;
	ot->poll = generators_gradient_poll;
	ot->cancel = generators_gradient_cancel;

	/* flags */
	ot->flag = OPTYPE_BLOCKING | OPTYPE_GRAB_CURSOR;
}

static int generators_radial_grad_invoke(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_radial_grad_exec(bContext *C, wmOperator *op)
{
	return 0;
}

static int generators_radial_grad_modal(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_radial_grad_poll(struct bContext *C)
{
	return ED_operator_terrain_active(C);
}

static void generators_radial_grad_cancel(bContext *C, wmOperator *op)
{
}

void TERRAIN_OT_generators_radial_grad(wmOperatorType *ot)
{
	/* identifiers */
	ot->name = "Radial gradient";
	ot->description = "Radial gradient generator";
	ot->idname = "TERRAIN_OT_generators_radial_grad";

	/* api callbacks */
	ot->invoke = generators_radial_grad_invoke;
	ot->modal = generators_radial_grad_modal;
	ot->poll = generators_radial_grad_poll;
	ot->cancel = generators_radial_grad_cancel;

	/* flags */
	ot->flag = OPTYPE_BLOCKING | OPTYPE_GRAB_CURSOR;
}

static int generators_voronoi_invoke(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_voronoi_exec(bContext *C, wmOperator *op)
{
	return 0;
}

static int generators_voronoi_modal(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_voronoi_poll(struct bContext *C)
{
	return ED_operator_terrain_active(C);
}

static void generators_voronoi_cancel(bContext *C, wmOperator *op)
{
}

void TERRAIN_OT_generators_voronoi(wmOperatorType *ot)
{
	/* identifiers */
	ot->name = "Voronoi";
	ot->description = "Voronoi generator";
	ot->idname = "TERRAIN_OT_generators_voronoi";

	/* api callbacks */
	ot->invoke = generators_voronoi_invoke;
	ot->modal = generators_voronoi_modal;
	ot->poll = generators_voronoi_poll;
	ot->cancel = generators_voronoi_cancel;

	/* flags */
	ot->flag = OPTYPE_BLOCKING | OPTYPE_GRAB_CURSOR;
}

static int generators_perlin_noise_invoke(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_perlin_noise_exec(bContext *C, wmOperator *op)
{
	return 0;
}

static int generators_perlin_noise_modal(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_perlin_noise_poll(struct bContext *C)
{
	return ED_operator_terrain_active(C);
}

static void generators_perlin_noise_cancel(bContext *C, wmOperator *op)
{
}

void TERRAIN_OT_generators_perlin_noise(wmOperatorType *ot)
{
	/* identifiers */
	ot->name = "Perlin noise";
	ot->description = "Perlin noise generator";
	ot->idname = "TERRAIN_OT_generators_perlin_noise";

	/* api callbacks */
	ot->invoke = generators_perlin_noise_invoke;
	ot->modal = generators_perlin_noise_modal;
	ot->poll = generators_perlin_noise_poll;
	ot->cancel = generators_perlin_noise_cancel;

	/* flags */
	ot->flag = OPTYPE_BLOCKING | OPTYPE_GRAB_CURSOR;
}

static int generators_file_input_invoke(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_file_input_exec(bContext *C, wmOperator *op)
{
	return 0;
}

static int generators_file_input_modal(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_file_input_poll(struct bContext *C)
{
	return ED_operator_terrain_active(C);
}

static void generators_file_input_cancel(bContext *C, wmOperator *op)
{
}

void TERRAIN_OT_generators_file_input(wmOperatorType *ot)
{
	/* identifiers */
	ot->name = "File input";
	ot->description = "File input  generator";
	ot->idname = "TERRAIN_OT_generators_file_input";

	/* api callbacks */
	ot->invoke = generators_file_input_invoke;
	ot->modal = generators_file_input_modal;
	ot->poll = generators_file_input_poll;
	ot->cancel = generators_file_input_cancel;

	/* flags */
	ot->flag = OPTYPE_BLOCKING | OPTYPE_GRAB_CURSOR;
}

static int generators_advanced_perlin_invoke(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_advanced_perlin_exec(bContext *C, wmOperator *op)
{
	return 0;
}

static int generators_advanced_perlin_modal(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_advanced_perlin_poll(struct bContext *C)
{
	return ED_operator_terrain_active(C);
}

static void generators_advanced_perlin_cancel(bContext *C, wmOperator *op)
{
}

void TERRAIN_OT_generators_advanced_perlin(wmOperatorType *ot)
{
	/* identifiers */
	ot->name = "Advanced Perlin";
	ot->description = "Advanced Perlin generator";
	ot->idname = "TERRAIN_OT_generators_advanced_perlin";

	/* api callbacks */
	ot->invoke = generators_advanced_perlin_invoke;
	ot->modal = generators_advanced_perlin_modal;
	ot->poll = generators_advanced_perlin_poll;
	ot->cancel = generators_advanced_perlin_cancel;

	/* flags */
	ot->flag = OPTYPE_BLOCKING | OPTYPE_GRAB_CURSOR;
}

static int generators_color_generator_invoke(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_color_generator_exec(bContext *C, wmOperator *op)
{
	return 0;
}

static int generators_color_generator_modal(bContext *C, wmOperator *op, 
		const wmEvent *event)
{
	return 0;
}

static int generators_color_generator_poll(struct bContext *C)
{
	return ED_operator_terrain_active(C);
}

static void generators_color_generator_cancel(bContext *C, wmOperator *op)
{
}

void TERRAIN_OT_generators_color_generator(wmOperatorType *ot)
{
	/* identifiers */
	ot->name = "Color";
	ot->description = "Color generator";
	ot->idname = "TERRAIN_OT_generators_color_generator";

	/* api callbacks */
	ot->invoke = generators_color_generator_invoke;
	ot->modal = generators_color_generator_modal;
	ot->poll = generators_color_generator_poll;
	ot->cancel = generators_color_generator_cancel;

	/* flags */
	ot->flag = OPTYPE_BLOCKING | OPTYPE_GRAB_CURSOR;
}

