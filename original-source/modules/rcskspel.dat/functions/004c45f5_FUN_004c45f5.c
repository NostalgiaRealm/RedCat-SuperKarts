/*
 * FUN_004c45f5 at 004c45f5
 * undefined FUN_004c45f5(void)
 * Address ranges: 004c45f5-004c4618
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c45f5(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  do {
    *param_1 = *param_1 + 1;
    uVar1 = FUN_004c45c4(param_2);
    iVar2 = FUN_004c9b7e(uVar1);
  } while (iVar2 != 0);
  return uVar1;
}

