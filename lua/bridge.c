#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#ifdef _HAS_H
#include "lua.h"
#else
extern unsigned char *source_lua;
extern int source_lua_len;
#endif

void lua() {
    source_lua[source_lua_len] = 0;
    lua_State *l = luaL_newstate();
    luaL_openlibs(l);
    luaL_loadstring(l, (const char *)source_lua);
    lua_pcall(l, 0, 0, 0);
    luaL_dostring(l, "lua()");
    lua_close(l);
}