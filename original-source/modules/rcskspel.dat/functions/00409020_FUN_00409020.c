/*
 * FUN_00409020 at 00409020
 * undefined FUN_00409020(void)
 * Address ranges: 00409020-00409115
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409020(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = (&DAT_00505108)[param_1 * 9] * 0xd0;
  iVar3 = iVar5 + DAT_0067ee20;
  if (*(int *)(iVar5 + 0x4c + DAT_0067ee20) == 1) {
    (&DAT_0050510c)[param_1 * 9] = 3;
    *(undefined4 *)(&DAT_00505124 + param_1 * 0x24) = 0x40000000;
    *(undefined4 *)(iVar3 + 0x48) = 0;
    return;
  }
  if (*(int *)(iVar3 + 0x1c) != (&DAT_00505110)[param_1 * 9]) {
    (&DAT_00505110)[param_1 * 9] = *(int *)(iVar3 + 0x1c);
    iVar3 = FUN_004be6c9();
    if ((0x32 < iVar3 % 100) && (cVar2 = FUN_00408f20(param_1), cVar2 == '\x01')) {
      return;
    }
    iVar1 = DAT_00680b28;
    iVar4 = 0;
    iVar3 = iVar5 + DAT_0067ee20;
    do {
      if (*(int *)(iVar1 + 0xec + (iVar4 + *(int *)(iVar3 + 0x1c) * 0x261) * 4) == 0x2c) {
        (&DAT_0050510c)[param_1 * 9] = 2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
  }
  if (((*(int *)(*(int *)(iVar3 + 0x24) * 0x50 + 4 + DAT_00680ae0) == 10) && (DAT_004ecd7c == 0)) &&
     ((*(uint *)(&DAT_00505114 + param_1 * 0x24) & 0x800) == 0)) {
    (&DAT_0050510c)[param_1 * 9] = 1;
  }
  return;
}

