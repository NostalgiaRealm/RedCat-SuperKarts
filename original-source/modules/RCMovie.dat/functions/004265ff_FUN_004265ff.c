/*
 * FUN_004265ff at 004265ff
 * undefined4 __cdecl FUN_004265ff(uint param_1, uint param_2, uint * param_3)
 * Address ranges: 004265ff-0042661f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004265ff(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_1 + param_2;
  if ((uVar1 < param_1) || (uVar1 < param_2)) {
    uVar2 = 1;
  }
  *param_3 = uVar1;
  return uVar2;
}

