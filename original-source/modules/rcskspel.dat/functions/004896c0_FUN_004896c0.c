/*
 * FUN_004896c0 at 004896c0
 * undefined FUN_004896c0(void)
 * Address ranges: 004896c0-004897d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004896c0(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x101) != '\0') {
    iVar1 = *(int *)(param_1 + 0x110) + 0x19;
    *(int *)(param_1 + 0x110) = iVar1;
    if (0xff < iVar1) {
      *(undefined4 *)(param_1 + 0x110) = 0;
    }
    iVar1 = *(int *)(param_1 + 0x114) + 0x4b;
    *(int *)(param_1 + 0x114) = iVar1;
    if (0xff < iVar1) {
      *(undefined4 *)(param_1 + 0x114) = 0;
    }
    iVar1 = *(int *)(param_1 + 0x118) + 0x7d;
    *(int *)(param_1 + 0x118) = iVar1;
    if (0xff < iVar1) {
      *(undefined4 *)(param_1 + 0x118) = 0;
    }
    *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x10) =
         ((*(uint *)(param_1 + 0x110) | 0xffffff00) << 8 | *(uint *)(param_1 + 0x114)) << 8 |
         *(uint *)(param_1 + 0x118);
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x14) = 0;
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar1 + 0x10);
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x14);
    return;
  }
  iVar1 = *(int *)(param_1 + 0xfc) * 0xc;
  *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x10) =
       ((*(uint *)(&DAT_004f9e60 + iVar1) | 0xffffff00) << 8 | *(uint *)(&DAT_004f9e64 + iVar1)) <<
       8 | *(uint *)(&DAT_004f9e68 + iVar1);
  *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x14) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x14);
  return;
}

