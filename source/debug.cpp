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
 
#include <switch.h>
#include <stratosphere.hpp>
#include <cstring>
#include "debug.hpp"

void Reboot() {
    /* ... */
}

void Log(char * data, u64 size) {
  //
  //return
  FsFileSystem g_sd_filesystem;
  FsFile f;
  if(R_SUCCEEDED(fsMountSdcard(&g_sd_filesystem))) {
    u64 lsize;
    u64 offset;
    //void * ldata;
    if(R_FAILED(fsFsOpenFile(&g_sd_filesystem, "/debug_layeredfs.txt", FS_OPEN_READ | FS_OPEN_WRITE, &f))) {
      lsize = size;
      offset = 0;
      fsFsCreateFile(&g_sd_filesystem, "/debug_layeredfs.txt", size, 0);
      fsFsOpenFile(&g_sd_filesystem, "/debug_layeredfs.txt", FS_OPEN_READ | FS_OPEN_WRITE, &f);
    } else {
      fsFileGetSize(&f, &lsize);
      offset = lsize;
      lsize += size;
      //size_t r_s;
      //fsFileRead(&f, 0, (void *) ldata, lsize, &r_s);
    }
    fsFileSetSize(&f, lsize);
    fsFileWrite(&f, offset, data, size);
    fsFileClose(&f);
    //memset(data, 0, size);
  }

}