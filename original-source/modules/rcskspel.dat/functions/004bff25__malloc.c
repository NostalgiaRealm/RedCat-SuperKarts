/*
 * _malloc at 004bff25
 * void * __cdecl _malloc(size_t _Size)
 * Address ranges: 004bff25-004bff36
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _malloc  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_006b67bc);
  return pvVar1;
}

