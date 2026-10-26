/*
 * FUN_004932e0 at 004932e0
 * undefined FUN_004932e0(void)
 * Address ranges: 004932e0-00493347
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004932e0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  param_1 = param_1 * 0xd0;
  *(undefined4 *)(param_1 + 0x20 + DAT_0067ee20) = *(undefined4 *)(param_1 + 0x1c + DAT_0067ee20);
  iVar1 = param_1 + DAT_0067ee20;
  iVar2 = DAT_006a5c38 + *(int *)(param_1 + 0xc + DAT_0067ee20) * 0xa9;
  uVar3 = FUN_004977d0(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar2 + 0x50),
                       *(undefined4 *)(iVar2 + 0x54),*(undefined4 *)(iVar2 + 0x58));
  *(undefined4 *)(iVar1 + 0x1c) = uVar3;
  return;
}

