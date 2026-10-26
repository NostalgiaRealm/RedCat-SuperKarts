/*
 * FUN_0041f64a at 0041f64a
 * int __cdecl FUN_0041f64a(undefined1 * param_1, byte * param_2, undefined4 * param_3)
 * Address ranges: 0041f64a-0041f69a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_0041f64a(undefined1 *param_1,byte *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  undefined1 *local_1c;
  undefined4 local_18;
  
  local_1c = param_1;
  local_24 = param_1;
  local_18 = 0x42;
  local_20 = 0x7fffffff;
  iVar1 = FUN_0042195e((int *)&local_24,param_2,param_3);
  local_20 = local_20 + -1;
  if (local_20 < 0) {
    FUN_00422168(0,(int *)&local_24);
  }
  else {
    *local_24 = 0;
  }
  return iVar1;
}

