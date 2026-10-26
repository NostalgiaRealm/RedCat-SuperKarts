/*
 * FUN_00406170 at 00406170
 * undefined FUN_00406170(void)
 * Address ranges: 00406170-0040626e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00406170(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_004104ac == 0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_2 + 0x48) == 0) {
      if (*(int *)(param_2 + 0x4c) == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 2;
      }
    }
    else if (*(int *)(param_2 + 0x4c) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 3;
    }
    iVar2 = (*DAT_0041048c)(DAT_004104ac,*(undefined4 *)(param_2 + 0x40),uVar1);
    *(uint *)(param_2 + 100) = iVar2 + 3U & 0xfffffffc;
    *(uint *)(param_2 + 0x3c) = ((*(uint *)(param_2 + 0x14) >> 2) + 0xfff >> 8 & 0xfffff0) << 8;
    if (*(uint *)(param_2 + 0x3c) < *(uint *)(param_2 + 100)) {
      *(uint *)(param_2 + 0x3c) = *(uint *)(param_2 + 100);
    }
    iVar2 = (*DAT_00410498)(*(undefined4 *)(param_2 + 0x3c));
    *(int *)(param_2 + 0x54) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = (*DAT_00410498)(*(undefined4 *)(param_2 + 0x3c));
    *(int *)(param_2 + 0x58) = iVar2;
    if (iVar2 == 0) {
      (*DAT_00410480)(*(undefined4 *)(param_2 + 0x54));
      return 0;
    }
    iVar2 = (*DAT_004104a8)(DAT_004104ac);
    *(int *)(param_2 + 0x38) = iVar2;
    if (iVar2 == 0) {
      (*DAT_00410480)(*(undefined4 *)(param_2 + 0x54));
      (*DAT_00410480)(*(undefined4 *)(param_2 + 0x58));
      return 0;
    }
    FUN_00406270();
    iVar2 = DAT_0040e860;
    DAT_0040e860 = param_2;
    *(int *)(param_2 + 0x34) = iVar2;
    uVar1 = 1;
  }
  return uVar1;
}

