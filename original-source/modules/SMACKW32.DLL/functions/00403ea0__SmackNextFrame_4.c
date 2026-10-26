/*
 * _SmackNextFrame@4 at 00403ea0
 * undefined __stdcall _SmackNextFrame@4(int param_1)
 * Address ranges: 00403ea0-00403f42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackNextFrame_4(int param_1)

{
  int iVar1;
  uint uVar2;
  uint extraout_ECX;
  
                    /* 0x3ea0  21  _SmackNextFrame@4 */
  if (param_1 != 0) {
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
    }
    FUN_00404060();
    uVar2 = *(int *)(param_1 + 0x370) + 1;
    iVar1 = *(int *)(*(int *)(param_1 + 0x3b8) + *(int *)(param_1 + 0x370) * 4);
    *(uint *)(param_1 + 0x370) = uVar2;
    *(int *)(param_1 + 0x3b0) = *(int *)(param_1 + 0x3b0) + iVar1;
    if ((uVar2 < *(uint *)(param_1 + 0xc)) && ((*(byte *)(param_1 + 0x385) & 2) == 0)) {
      *(undefined4 *)(param_1 + 0x3b0) = *(undefined4 *)(param_1 + 0x3ac);
      FUN_004059b0(uVar2,*(undefined4 **)(param_1 + 0x3ac));
      uVar2 = extraout_ECX;
    }
    FUN_004053e0(uVar2);
    if (DAT_0040e83c != 0) {
      (*DAT_00410474)();
    }
  }
  return;
}

