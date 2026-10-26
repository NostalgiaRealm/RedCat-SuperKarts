/*
 * FUN_004be5e7 at 004be5e7
 * undefined FUN_004be5e7(void)
 * Address ranges: 004be5e7-004be653
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004be5e7(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_004c1d90(DAT_006b7dd4);
  if (uVar1 < (uint)((int)DAT_006b7dd0 + (4 - DAT_006b7dd4))) {
    iVar2 = FUN_004c1d90(DAT_006b7dd4);
    iVar2 = FUN_004c1c70(DAT_006b7dd4,iVar2 + 0x10);
    if (iVar2 == 0) {
      return;
    }
    DAT_006b7dd0 = (undefined4 *)(iVar2 + ((int)DAT_006b7dd0 - DAT_006b7dd4 >> 2) * 4);
    DAT_006b7dd4 = iVar2;
  }
  *DAT_006b7dd0 = param_1;
  DAT_006b7dd0 = DAT_006b7dd0 + 1;
  return;
}

