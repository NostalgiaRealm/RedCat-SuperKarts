/*
 * FUN_00428240 at 00428240
 * undefined FUN_00428240(void)
 * Address ranges: 00428240-004282d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00428240(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = FUN_00427ed0(param_1);
  iVar3 = FUN_00427f00(0);
  uVar1 = *(uint *)(&DAT_00535070 + iVar2 * 300 + iVar3 * 0x20);
  uVar5 = DAT_00534f40 >> 0x18;
  iVar2 = FUN_00427ed0(param_1);
  uVar5 = uVar5 / *(uint *)(&DAT_00535138 + iVar2 * 300);
  if (uVar5 == 0) {
    uVar5 = 1;
  }
  uVar4 = uVar1 >> 0x18;
  if (uVar4 != 0) {
    uVar4 = uVar4 - uVar5;
  }
  iVar2 = FUN_00427ed0(param_1);
  iVar3 = FUN_00427f00(0);
  *(uint *)(&DAT_00535070 + iVar2 * 300 + iVar3 * 0x20) = uVar1 & 0xffffff | uVar4 << 0x18;
  return;
}

