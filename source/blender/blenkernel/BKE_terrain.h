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

#ifndef __BKE_TERRAIN_H__
#define __BKE_TERRAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

enum {
	TE_MODE_BLUEPRINT = 0,
    TE_MODE_EXPLORER,
    TE_MODE_LAYOUT,
    TE_MODE_VIEW3D,
    TE_MODE_VIEW2D
};

struct Main;
struct Terrain;
struct TerrainBlueprint;
struct TerrainBlueprintDescription;
struct TerrainBlueprintSettings;

void BKE_terrain_free(struct Terrain *terrain);
void BKE_terrain_unlink(struct Main *bmain, struct Terrain *terrain);
struct Terrain *BKE_terrain_add(struct Main *bmain, const char *name);
struct Terrain *BKE_terrain_copy(struct Terrain *terrain);

void BKE_terrain_blueprint_free(struct TerrainBlueprint *blueprint);
struct TerrainBlueprint *BKE_terrain_blueprint_add(void);
struct TerrainBlueprint *BKE_terrain_blueprint_copy(
        struct TerrainBlueprint *blueprint);

void BKE_terrain_blueprint_description_free(
        struct TerrainBlueprintDescription *description);
struct TerrainBlueprintDescription *BKE_terrain_blueprint_description_add(void);
struct TerrainBlueprintDescription *BKE_terrain_blueprint_description_copy(
        struct TerrainBlueprintDescription* description);

void BKE_terrain_blueprint_settings_free(
        struct TerrainBlueprintSettings *settings);
struct TerrainBlueprintSettings *BKE_terrain_blueprint_settings_add(void);
struct TerrainBlueprintSettings *BKE_terrain_blueprint_settings_copy(
        struct TerrainBlueprintSettings* settings);


#ifdef __cplusplus
}
#endif

#endif /* __BKE_TERRAIN_H__ */
