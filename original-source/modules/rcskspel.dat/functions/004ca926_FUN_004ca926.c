/*
 * FUN_004ca926 at 004ca926
 * undefined FUN_004ca926(void)
 * Address ranges: 004ca926-004ca946
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004ca926(uint param_1,uint param_2,uint *param_3)

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

