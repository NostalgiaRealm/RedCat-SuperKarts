/*
 * FUN_004884d0 at 004884d0
 * undefined FUN_004884d0(void)
 * Address ranges: 004884d0-004885b3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004884d0(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  if (*(char *)(param_1 + 0x150) == '\0') {
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x154)) {
      puVar4 = (undefined4 *)(param_1 + 0x14);
      do {
        iVar2 = *(int *)(param_1 + 0x14c) * 0xc;
        iVar5 = iVar5 + 1;
        puVar4[-1] = ((*(uint *)(&DAT_004f9e60 + iVar2) | 0xffffff00) << 8 |
                     *(uint *)(&DAT_004f9e64 + iVar2)) << 8 | *(uint *)(&DAT_004f9e68 + iVar2);
        *puVar4 = 0;
        puVar4 = puVar4 + 8;
      } while (iVar5 < *(int *)(param_1 + 0x154));
    }
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x10);
    uVar1 = (uVar3 >> 0x10 & 0xff) + 0x2d;
    if (0xff < uVar1) {
      uVar1 = 0;
    }
    uVar6 = (uVar3 >> 8 & 0xff) + 0x41;
    if (0xff < uVar6) {
      uVar6 = 0;
    }
    uVar3 = (uVar3 & 0xff) + 0x55;
    if (0xff < uVar3) {
      uVar3 = 0;
    }
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x154)) {
      puVar4 = (undefined4 *)(param_1 + 0x14);
      do {
        puVar4[-1] = ((uVar1 | 0xffffff00) << 8 | uVar6) << 8 | uVar3;
        *puVar4 = 0;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 8;
      } while (iVar5 < *(int *)(param_1 + 0x154));
      return;
    }
  }
  return;
}

