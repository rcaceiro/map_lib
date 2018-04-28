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

#include <stdio.h>
#include <string.h>
#include "map_lib.h"

struct map_t *map_create()
{
 struct map_t *m;
 m=(struct map_t *)calloc(1, sizeof(struct map_t));
 m->key=-1;
 return m;
}

bool map_set(struct map_t *m, int key, detection *value)
{
 if(m->key == -1)
 {
  m->key=key;
  m->value=value;
  m->nxt=NULL;
  return true;
 }

 for(struct map_t *map=m;; map=map->nxt)
 {
  if(key == map->key)
  {
   if(value->prob[key]>map->value->prob[map->key])
   {
    map->value=value;
    return true;
   }
   else
   {
    return false;
   }
  }
  else if(map->nxt == NULL)
  {
   map->nxt=(struct map_t *)calloc(1, sizeof(struct map_t));
   map=map->nxt;
   map->key=key;
   map->value=value;
   map->nxt=NULL;
   return true;
  }
 }
}

detection *map_get(struct map_t *m, int key)
{
 for(struct map_t *map=m; map != NULL; map=map->nxt)
 {
  if(key == map->key)
  {
   return map->value;
  }
 }
 return NULL;
}

void map_free(struct map_t *m)
{
 struct map_t *map, *nxt;
 map=nxt=m;
 while(map != NULL)
 {
  nxt=map->nxt;
  free(map);
  map=nxt;
 }
}

bool map_exists_key(struct map_t *m, int key)
{
 return map_get(m, key) == NULL;
}

void map_print(FILE *file, struct map_t *m)
{
 struct map_t *map=m;
 while(map != NULL && map->key>-1)
 {
  fprintf(file, "key=%i, provability=%f\n", map->key, map->value->prob[map->key]);
  map=map->nxt;
 }
}