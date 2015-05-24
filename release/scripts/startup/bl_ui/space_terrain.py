
import bpy

class TERRAIN_base:
    bl_space_type = 'TERRAIN'

class TERRAIN_Header_base(TERRAIN_base):
    pass

class TERRAIN_ToolsPanel_base(TERRAIN_base):
    bl_region_type = 'TOOLS'

class TERRAIN_HT_header(TERRAIN_Header_base, bpy.types.Header):
    
    def draw(self, context):
        layout = self.layout
        view = context.space_data
        mode = context.mode
        obj = context.active_object

        row = layout.row(align=True)
        row.template_header()
        sub = row.row(align=True)

        row = layout
        layout.template_header_terrain()

class HelloWorldPanel(TERRAIN_ToolsPanel_base, bpy.types.Panel):
    bl_label = "Hello World"

    def draw(self, context):
        self.layout.label(text="Hello World")

if __name__ == "__main__":  # only for live edit.
    bpy.utils.register_module(__name__)



