/*
 * FUN_004c1290 at 004c1290
 * undefined FUN_004c1290(void)
 * Address ranges: 004c1290-004c12b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c1290(undefined4 param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_004c890e(param_1);
  *(undefined8 *)param_2 = uVar2;
  uVar1 = 0xffffffff;
  if ((*param_2 & param_2[1]) != 0xffffffff) {
    uVar1 = 0;
  }
  return uVar1;
}

