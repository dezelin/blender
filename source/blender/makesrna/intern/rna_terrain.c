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

#include "DNA_terrain_types.h"

#include "BKE_terrain.h"

#include "RNA_access.h"
#include "RNA_define.h"
#include "RNA_enum_types.h"

#include "rna_internal.h"

#include "WM_api.h"
#include "WM_types.h"

EnumPropertyItem terrain_mode_items[] = {
	{TE_MODE_BLUEPRINT, "BLUEPRINT", ICON_TERRAIN_BLUEPRINT, "Blueprint", "Terrain blueprint"},
	{TE_MODE_EXPLORER, "EXPLORER", ICON_TERRAIN_EXPLORER, "Explorer", "Terrain explorer"},
	{TE_MODE_LAYOUT, "LAYOUT", ICON_TERRAIN_LAYOUT, "Layout", "Terrain layout"},
	{TE_MODE_VIEW3D, "VIEW3D", ICON_TERRAIN_VIEW3D, "3D View", "Terrain 3D view"},
	{TE_MODE_VIEW2D, "VIEW2D", ICON_TERRAIN_VIEW2D, "2D View", "Terrain 2D view"},
	{0, NULL, 0, NULL, NULL}
};

EnumPropertyItem terrain_type_items[] = {
	{TE_TYPE_BLUEPRINT, "BLUEPRINT", ICON_TERRAIN_BLUEPRINT, "Blueprint", "Terrain blueprint"},
	{0, NULL, 0, NULL, NULL}
};

#ifdef RNA_RUNTIME

static PointerRNA rna_TerrainBlueprint_description_get(PointerRNA *ptr)
{
    return *ptr;
}

static void rna_TerrainBlueprint_description_set(PointerRNA *ptr, PointerRNA value)
{
}

static PointerRNA rna_TerrainBlueprint_settings_get(PointerRNA *ptr)
{
    return *ptr;
}

static void rna_TerrainBlueprint_settings_set(PointerRNA *ptr, PointerRNA value)
{
}

#else

static void rna_def_terran_blueprint_settings(BlenderRNA *brna)
{
	StructRNA *srna;
	PropertyRNA *prop;

	srna = RNA_def_struct(brna, "TerrainBlueprintSettings", NULL);
	RNA_def_struct_ui_text(srna, "TerrainBlueprintSettings", "Terrain blueprint settings");
	RNA_def_struct_ui_icon(srna, ICON_NONE);

	prop = RNA_def_property(srna, "dummy", PROP_INT, PROP_NONE);
	RNA_def_property_int_sdna(prop, NULL, "dummy");
	RNA_def_property_ui_text(prop, "Dummy", "Dummy placeholder");
	RNA_def_property_update(prop, NC_TERRAIN | ND_DISPLAY, NULL);
}

static void rna_def_terran_blueprint_description(BlenderRNA *brna)
{
	StructRNA *srna;
	PropertyRNA *prop;

	srna = RNA_def_struct(brna, "TerrainBlueprintDescription", NULL);
	RNA_def_struct_ui_text(srna, "TerrainBlueprintDescription", "Terrain blueprint description");
	RNA_def_struct_ui_icon(srna, ICON_NONE);

	prop = RNA_def_property(srna, "author", PROP_STRING, PROP_NONE);
	RNA_def_property_string_sdna(prop, NULL, "author");
	RNA_def_property_ui_text(prop, "Author", "Blueprint author");
	RNA_def_property_update(prop, NC_TERRAIN | ND_DISPLAY, NULL);

	prop = RNA_def_property(srna, "author_email", PROP_STRING, PROP_NONE);
	RNA_def_property_string_sdna(prop, NULL, "author_email");
	RNA_def_property_ui_text(prop, "Email", "Blueprint author email address");
	RNA_def_property_update(prop, NC_TERRAIN | ND_DISPLAY, NULL);

	prop = RNA_def_property(srna, "copyright", PROP_STRING, PROP_NONE);
	RNA_def_property_string_sdna(prop, NULL, "copyright");
	RNA_def_property_ui_text(prop, "Copyright", "Blueprint copyright");
	RNA_def_property_update(prop, NC_TERRAIN | ND_DISPLAY, NULL);

	prop = RNA_def_property(srna, "description", PROP_STRING, PROP_NONE);
	RNA_def_property_string_sdna(prop, NULL, "description");
	RNA_def_property_ui_text(prop, "Description", "Blueprint short description");
	RNA_def_property_update(prop, NC_TERRAIN | ND_DISPLAY, NULL);

	prop = RNA_def_property(srna, "license", PROP_STRING, PROP_NONE);
	RNA_def_property_string_sdna(prop, NULL, "license");
	RNA_def_property_ui_text(prop, "License", "Blueprint copyright license");
	RNA_def_property_update(prop, NC_TERRAIN | ND_DISPLAY, NULL);
}

static void rna_def_terrain_blueprint(BlenderRNA *brna)
{
	StructRNA *srna;
	PropertyRNA *prop;

	srna = RNA_def_struct(brna, "TerrainBlueprint", NULL);
	RNA_def_struct_ui_text(srna, "TerrainBlueprint", "Terrain blueprint");
	RNA_def_struct_ui_icon(srna, ICON_NONE);

	prop = RNA_def_property(srna, "type", PROP_ENUM, PROP_NONE);
	RNA_def_property_enum_items(prop, terrain_type_items);
	RNA_def_property_clear_flag(prop, PROP_EDITABLE);
	RNA_def_property_ui_text(prop, "Type", "Terrain generator blueprint type");
	RNA_def_property_update(prop, NC_TERRAIN | ND_DISPLAY, NULL);

	prop = RNA_def_property(srna, "name", PROP_STRING, PROP_NONE);
	RNA_def_property_string_sdna(prop, NULL, "name");
	RNA_def_property_ui_text(prop, "Name", "Blueprint name");
	RNA_def_property_update(prop, NC_TERRAIN | ND_DISPLAY, NULL);

	prop = RNA_def_property(srna, "description", PROP_POINTER, PROP_NONE);
	RNA_def_property_struct_type(prop, "TerrainBlueprintDescription");
	RNA_def_property_pointer_sdna(prop, NULL, "description");
	RNA_def_property_pointer_funcs(prop, "rna_TerrainBlueprint_description_get", 
		"rna_TerrainBlueprint_description_set", NULL, NULL);
	RNA_def_property_ui_text(prop, "Description", "Terrain blueprint description");

	prop = RNA_def_property(srna, "settings", PROP_POINTER, PROP_NONE);
	RNA_def_property_struct_type(prop, "TerrainBlueprintSettings");
	RNA_def_property_pointer_sdna(prop, NULL, "settings");
	RNA_def_property_pointer_funcs(prop, "rna_TerrainBlueprint_settings_get",
		"rna_TerrainBlueprint_settings_set", NULL, NULL);
	RNA_def_property_ui_text(prop, "Settings", "Terrain blueprint settings");
}

static void rna_def_terrain(BlenderRNA *brna)
{
	StructRNA *srna;
	PropertyRNA *prop;

	srna = RNA_def_struct(brna, "Terrain", NULL);
	RNA_def_struct_ui_text(srna, "Terrain", "Terrain blueprint data block");
	RNA_def_struct_ui_icon(srna, ICON_NONE);

	prop = RNA_def_property(srna, "blueprint", PROP_POINTER, PROP_NONE);
	RNA_def_property_struct_type(prop, "TerrainBlueprint");
	RNA_def_property_pointer_sdna(prop, NULL, "blueprint");
	RNA_def_property_flag(prop, PROP_NEVER_NULL);
	RNA_def_property_ui_text(prop, "Terrain blueprint", "Terrain blueprint");
	
    prop = RNA_def_property(srna, "mode", PROP_ENUM, PROP_NONE);
	RNA_def_property_enum_sdna(prop, NULL, "mode");
	RNA_def_property_enum_items(prop, terrain_mode_items);
	RNA_def_property_clear_flag(prop, PROP_EDITABLE);
	RNA_def_property_ui_text(prop, "Mode", "Terrain interaction mode");

	RNA_api_terrain(srna);
}

void RNA_def_terrain(BlenderRNA *brna)
{
	rna_def_terran_blueprint_settings(brna);
	rna_def_terran_blueprint_description(brna);
	rna_def_terrain_blueprint(brna);
	rna_def_terrain(brna);
}

#endif /* RNA_RUNTIME */
