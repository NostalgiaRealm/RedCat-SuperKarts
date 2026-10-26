/*
 * operator_new at 004be7ee
 * void * __cdecl operator_new(uint param_1)
 * Address ranges: 004be7ee-004be7fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  void * __cdecl operator new(unsigned int)  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}

