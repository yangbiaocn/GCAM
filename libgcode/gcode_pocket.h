/*
*  gcode_pocket.h
*  Source code file for G-Code generation, simulation, and visualization
*  library. This software is Copyright (C) 2006 by Justin Shumaker
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _GCODE_POCKET_H
#define _GCODE_POCKET_H

#include "gcode_internal.h"
#include "gcode_tool.h"

typedef struct gcode_pocket_row_s
{
  int line_num;
  gcode_vec2d_t *line_array;
  gfloat_t y;
} gcode_pocket_row_t;

typedef struct gcode_pocket_s
{
  int row_num;
  int seg_num;
  gcode_pocket_row_t *row_array;
  gfloat_t resolution;
} gcode_pocket_t;

void gcode_pocket_init (gcode_pocket_t *pocket, gfloat_t resolution);
void gcode_pocket_free (gcode_pocket_t *pocket);
void gcode_pocket_prep (gcode_pocket_t *pocket, gcode_block_t *start_block, gcode_block_t *end_block);
void gcode_pocket_make (gcode_pocket_t *pocket, gcode_block_t *code_block, gfloat_t depth, gfloat_t rapid_depth, gcode_tool_t *tool);
void gcode_pocket_subtract (gcode_pocket_t *pocket_a, gcode_pocket_t *pocket_b);

#endif
