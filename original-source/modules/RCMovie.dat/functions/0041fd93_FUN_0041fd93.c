/*
 * FUN_0041fd93 at 0041fd93
 * undefined __cdecl FUN_0041fd93(LPVOID param_1)
 * Address ranges: 0041fd93-0041fdc1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041fd93(LPVOID param_1)

{
  uint *puVar1;
  
  if (param_1 != (LPVOID)0x0) {
    puVar1 = (uint *)FUN_00422b65((int)param_1);
    if (puVar1 != (uint *)0x0) {
      FUN_00422b90(puVar1,(uint)param_1);
      return;
    }
    HeapFree(DAT_0043f81c,0,param_1);
  }
  return;
}

