/*
 * FUN_004019af at 004019af
 * int __cdecl FUN_004019af(undefined1 * param_1, int param_2, byte * param_3)
 * Address ranges: 004019af-004019ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_004019af(undefined1 *param_1,int param_2,byte *param_3)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = param_2;
  iVar1 = FUN_00403396((int *)&local_24,param_3,(undefined4 *)&stack0x00000010);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_00402785(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}

