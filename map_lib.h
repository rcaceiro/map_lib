// map_lib
// A simple associative-array library for C
//
// License: MIT / X11
// Copyright (c) 2009, 2012 by James K. Lawless
// jimbo@radiks.net http://www.radiks.net/~jimbo
// http://www.mailsend-online.com
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.


#ifndef MAP_LIB_H
#define MAP_LIB_H

#include "darknet.h"
#include <stdbool.h>

struct map_t
{
 struct map_t *nxt;
 int key;
 detection *value;
};


struct map_t *map_create();
detection *map_get(struct map_t *m, int key);
bool map_exists_key(struct map_t *m, int key);
bool map_set(struct map_t *m, int key, detection *value);
void map_free(struct map_t *m);

bool map_empty(struct map_t *m);

int map_size(struct map_t *m);
void map_print(FILE *file, struct map_t *m);
#endif