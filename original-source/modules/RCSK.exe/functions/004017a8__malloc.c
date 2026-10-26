/*
 * _malloc at 004017a8
 * void * __cdecl _malloc(size_t _Size)
 * Address ranges: 004017a8-004017b9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  _malloc  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00408c5c);
  return pvVar1;
}

