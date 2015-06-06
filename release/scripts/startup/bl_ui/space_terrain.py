
import bpy


class TERRAIN_Base:
    bl_space_type = "TERRAIN"

#
# Terrain header
#


class TERRAIN_HeaderBase(TERRAIN_Base):
    pass


class TERRAIN_Header(TERRAIN_HeaderBase, bpy.types.Header):
    def draw(self, context):
        layout = self.layout
        # view = context.space_data
        # mode = context.mode
        # obj = context.active_object

        row = layout.row(align=True)
        row.template_header()
        sub = row.row(align=True)

        row = layout
        layout.template_header_terrain()

#
# Terrain tool panels
#


class TERRAIN_ToolPanel(TERRAIN_Base):
    bl_region_type = "TOOLS"


#
# Terrain Blueprint tool panels
#

class TERRAIN_BlueprintToolPanel(bpy.types.Panel, TERRAIN_ToolPanel):
    bl_category = "Tools"
    bl_label = "Tools"
    bl_conext = "blueprint"

    def draw(self, context):
        self.layout.label(text="Hello World")

#
# Terrain Blueprint devices panels
#


class TERRAIN_BlueprintGeneratorDevicesPanel(bpy.types.Panel,
                                             TERRAIN_ToolPanel):
    bl_category = "Devices"
    bl_label = "Generators"
    bl_conext = "blueprint"

    def draw(self, context):
        layout = self.layout

        col = layout.column(align=True)
        col.operator("terrain.generators_layout")
        col.operator("terrain.generators_color_generator")
        col.operator("terrain.generators_constant")
        col.operator("terrain.generators_gradient")
        col.operator("terrain.generators_radial_grad")
        col.operator("terrain.generators_voronoi")

        col.separator()

        col.operator("terrain.generators_perlin_noise")
        col.operator("terrain.generators_advanced_perlin")

        col.separator()

        col.operator("terrain.generators_file_input")


class TERRAIN_BlueprintOutputDevicesPanel(bpy.types.Panel, TERRAIN_ToolPanel):
    bl_category = "Devices"
    bl_label = "Outputs"
    bl_conext = "blueprint"

    def draw(self, context):
        self.layout.label(text="Hello World")


class TERRAIN_BlueprintCombinersDevicesPanel(bpy.types.Panel,
                                             TERRAIN_ToolPanel):
    bl_category = "Devices"
    bl_label = "Combiners"
    bl_conext = "blueprint"

    def draw(self, context):
        self.layout.label(text="Hello World")


class TERRAIN_BlueprintFiltersDevicesPanel(bpy.types.Panel, TERRAIN_ToolPanel):
    bl_category = "Devices"
    bl_label = "Filters"
    bl_conext = "blueprint"

    def draw(self, context):
        self.layout.label(text="Hello World")


class TERRAIN_BlueprintNaturalFiltersDevicesPanel(bpy.types.Panel,
                                                  TERRAIN_ToolPanel):
    bl_category = "Devices"
    bl_label = "Natural filters"
    bl_conext = "blueprint"

    def draw(self, context):
        self.layout.label(text="Hello World")


class TERRAIN_BlueprintSelectorDevicesPanel(bpy.types.Panel, TERRAIN_ToolPanel):
    bl_category = "Devices"
    bl_label = "Selector"
    bl_conext = "blueprint"

    def draw(self, context):
        self.layout.label(text="Hello World")


class TERRAIN_BlueprintConvertorDevicesPanel(bpy.types.Panel,
                                             TERRAIN_ToolPanel):
    bl_category = "Devices"
    bl_label = "Convertors"
    bl_conext = "blueprint"

    def draw(self, context):
        self.layout.label(text="Hello World")


class TERRAIN_BlueprintFlowControlDevicesPanel(bpy.types.Panel,
                                               TERRAIN_ToolPanel):
    bl_category = "Devices"
    bl_label = "Generators"
    bl_conext = "blueprint"

    def draw(self, context):
        self.layout.label(text="Hello World")


def register():
    bpy.utils.register_module(__name__)


def unregister():
    bpy.utils.unregister_module(__name__)


if __name__ == "__main__":  # only for live edit.
    register()
