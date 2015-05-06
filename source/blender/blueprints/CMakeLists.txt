# ***** BEGIN GPL LICENSE BLOCK *****
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#
# The Original Code is Copyright (C) 2015, Aleksandar Dezelin
# All rights reserved.
#
# The Original Code is: all of this file.
#
# Contributor(s): none yet.
#
# ***** END GPL LICENSE BLOCK *****

set(INC
	.
	../blenlib
	../makesdna
	../../blenlib
)

set(INC_SYS
	.
)

set(SRC
	intern/blueprint.c
	intern/blueprintconn.c
	intern/blueprintdescription.c
	intern/blueprintevent.c
	intern/blueprintgroup.c
	intern/blueprintfunc.c
	intern/blueprintinputport.c
	intern/blueprintnode.c
	intern/blueprintport.c
	intern/blueprintoutputport.c
	intern/blueprintsettings.c
	intern/blueprintvar.c
	BP_blueprint.h
	BP_blueprintconn.h
	BP_blueprintdescription.h
	BP_blueprintevent.h
	BP_blueprintgroup.h
	BP_blueprintfunc.h
	BP_blueprintinputport.h
	BP_blueprintnode.h
	BP_blueprintoutputport.h
	BP_blueprintport.h
	BP_blueprintsettings.h
	BP_blueprintvar.h
)

blender_add_lib(bf_blueprints "${SRC}" "${INC}" "${INC_SYS}")
