/*
 * FUN_00411410 at 00411410
 * undefined FUN_00411410(void)
 * Address ranges: 00411410-0041147a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00411410(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  param_1 = param_1 * 0x50;
  puVar2 = param_2;
  if (*(int *)(param_1 + 0x24 + DAT_00680ae0) < 1) {
    *param_2 = 0xffffffff;
    return *(undefined4 *)(param_1 + 0x24 + DAT_00680ae0);
  }
  do {
    uVar1 = FUN_004944a0(iVar3);
    *puVar2 = uVar1;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 < *(int *)(param_1 + 0x24 + DAT_00680ae0));
  param_2[iVar3] = 0xffffffff;
  return *(undefined4 *)(param_1 + 0x24 + DAT_00680ae0);
}

