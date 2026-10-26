/*
 * FUN_004a08a0 at 004a08a0
 * undefined FUN_004a08a0(void)
 * Address ranges: 004a08a0-004a09ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004a08a0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  param_1[0x23] = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x95) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x99) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x91) = 0xffffffff;
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x1d] = 0;
  *param_1 = 2;
  param_1[0x1e] = 0;
  *(undefined4 *)((int)param_1 + 0xa1) = 1;
  param_1[0x1f] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x20] = 0x3f800000;
  param_1[0x21] = 0x3f800000;
  param_1[0x22] = 0x3f800000;
  puVar2 = &DAT_006a5c90;
  puVar3 = param_1 + 4;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(code **)((int)param_1 + 0x9d) = FUN_004a0610;
  *(undefined1 *)(param_1 + 0x24) = 1;
  *(undefined4 *)((int)param_1 + 0xa5) = 0;
  return;
}

