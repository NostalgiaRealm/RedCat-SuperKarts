/*
 * FUN_00401779 at 00401779
 * undefined __cdecl FUN_00401779(LPVOID param_1)
 * Address ranges: 00401779-004017a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00401779(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    puVar1 = (uint *)FUN_00402b28((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_00402b53(puVar1,(uint)param_1);
      return;
    }
    HeapFree(DAT_0040a01c,0,param_1);
  }
  return;
}

