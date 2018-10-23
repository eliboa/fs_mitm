/*
 * Copyright (c) 2018 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef EXOSPHERE_THERMOSPHERE_H
#define EXOSPHERE_THERMOSPHERE_H

#include "utils.h"

#define MAGIC_TMS0 (0x30534D54)

typedef struct {
    uint32_t magic;
    uint32_t rel_ep;
    uint32_t reserved[2];
} thermosphere_header_t;

void thermosphere_detect(void *section, size_t sec_size);
bool thermosphere_is_present(void);
uintptr_t thermosphere_get_entrypoint(void);

#endif