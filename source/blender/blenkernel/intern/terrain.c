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
* Contributor(s): not yeat.
*
* ***** END GPL LICENSE BLOCK *****
*/

#include "MEM_guardedalloc.h"

#include "DNA_terrain_types.h"

#include "BKE_library.h"
#include "BKE_main.h"
#include "BKE_terrain.h"

#include "BLI_string.h"


#define UNKNOWN_BLUEPRINT_NAME "Blueprint0"
#define BLUEPRINT_MEM_STRING "TerrainBlueprint"
#define DESCRIPTION_MEM_STRING "TerrainBlueprintDescription"
#define SETTINGS_MEM_STRING "TerrainBlueprintSettings"


void BKE_terrain_free(Terrain *terrain)
{
	BKE_terrain_blueprint_free(terrain->blueprint);
	MEM_freeN(terrain);
}

void BKE_terrain_unlink(Main *bmain, Terrain *terrain)
{
	BKE_libblock_free(bmain, &terrain->id);
}

Terrain *BKE_terrain_add(Main *bmain, const char *name)
{
	Terrain *tr;

	tr = BKE_libblock_alloc(bmain, ID_TRN, name);
	tr->blueprint = BKE_terrain_blueprint_add(); 

	return tr;
}

Terrain *BKE_terrain_copy(Terrain *terrain)
{
	Terrain *tr;

	tr = BKE_libblock_copy(&terrain->id);
	return tr;
}

void BKE_terrain_blueprint_free(TerrainBlueprint *blueprint)
{
	MEM_SAFE_FREE(blueprint->name);
	BKE_terrain_blueprint_description_free(blueprint->description);
	BKE_terrain_blueprint_settings_free(blueprint->settings);

	/* TODO: Free nodes */
}

TerrainBlueprint *BKE_terrain_blueprint_add(void)
{
	TerrainBlueprint *blueprint = MEM_callocN(sizeof(TerrainBlueprint),
			BLUEPRINT_MEM_STRING);
	blueprint->type = TE_TYPE_BLUEPRINT;
	blueprint->name = BLI_strdup(UNKNOWN_BLUEPRINT_NAME);
	blueprint->description = BKE_terrain_blueprint_description_add();
	blueprint->settings = BKE_terrain_blueprint_settings_add();

	/* TODO: Allocate nodes */
	return blueprint;
}

TerrainBlueprint *BKE_terrain_blueprint_copy(TerrainBlueprint *blueprint)
{
	TerrainBlueprint *copy = MEM_callocN(sizeof(TerrainBlueprint),
			BLUEPRINT_MEM_STRING);
	copy->type = blueprint->type;
	copy->name = MEM_dupallocN(blueprint->name);
	copy->description = BKE_terrain_blueprint_description_copy(
			blueprint->description);
	copy->settings = BKE_terrain_blueprint_settings_copy(blueprint->settings);

	/* TODO: Copy nodes */
	return copy;
}

void BKE_terrain_blueprint_description_free(
		TerrainBlueprintDescription *description)
{
	MEM_SAFE_FREE(description->author);
	MEM_SAFE_FREE(description->author_email);
	MEM_SAFE_FREE(description->copyright);
	MEM_SAFE_FREE(description->description);
	MEM_SAFE_FREE(description->license);
	MEM_freeN(description);
}

TerrainBlueprintDescription *BKE_terrain_blueprint_description_add(void)
{
	return MEM_callocN(sizeof(TerrainBlueprintDescription), 
			DESCRIPTION_MEM_STRING);
}

TerrainBlueprintDescription *BKE_terrain_blueprint_description_copy(
		TerrainBlueprintDescription* description)
{
	TerrainBlueprintDescription *copy = 
	MEM_mallocN(sizeof(TerrainBlueprintDescription), DESCRIPTION_MEM_STRING);
	copy->author = MEM_dupallocN(description->author);
	copy->author_email = MEM_dupallocN(description->author_email);
	copy->copyright = MEM_dupallocN(description->copyright);
	copy->description = MEM_dupallocN(description->description);
	copy->license = MEM_dupallocN(description->license);
	return copy;
}

void BKE_terrain_blueprint_settings_free(TerrainBlueprintSettings *settings)
{
	MEM_freeN(settings);
}

TerrainBlueprintSettings *BKE_terrain_blueprint_settings_add(void)
{
	return MEM_callocN(sizeof(TerrainBlueprintSettings), SETTINGS_MEM_STRING);
}

TerrainBlueprintSettings *BKE_terrain_blueprint_settings_copy(
		TerrainBlueprintSettings* settings)
{
	return MEM_dupallocN(settings);
}

