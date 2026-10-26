/*
 * __nh_malloc at 004bff37
 * void * __cdecl __nh_malloc(size_t _Size, int _NhFlag)
 * Address ranges: 004bff37-004bff62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __nh_malloc  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  void *pvVar1;
  int iVar2;
  
  if (_Size < 0xffffffe1) {
    do {
      pvVar1 = (void *)FUN_004bff63(_Size);
      if (pvVar1 != (void *)0x0) {
        return pvVar1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      iVar2 = FUN_004c62bb(_Size);
    } while (iVar2 != 0);
  }
  return (void *)0x0;
}

