/*
 * FUN_0040d070 at 0040d070
 * undefined FUN_0040d070(void)
 * Address ranges: 0040d070-0040d1a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040d070(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((&DAT_00503ef4)[param_1 * 0x47] != 0x1c) {
    cVar1 = FUN_00417e90(param_1);
    iVar3 = DAT_0053be60;
    if (cVar1 == '\0') {
      iVar3 = (&DAT_005081b8)[param_1 * 0x1c];
    }
    if (iVar3 != 0) {
      iVar2 = FUN_00410160();
      cVar1 = FUN_00417e90(param_1);
      iVar3 = DAT_0053be60;
      if (cVar1 == '\0') {
        iVar3 = (&DAT_005081b8)[param_1 * 0x1c];
      }
      iVar5 = DAT_0053be60 + 1;
      cVar1 = FUN_00417e90(param_1);
      iVar4 = DAT_0053be60;
      if (cVar1 == '\0') {
        iVar4 = (&DAT_005081b8)[param_1 * 0x1c];
      }
      if ((*(int *)(&DAT_00503fd8 + param_1 * 0x11c) == iVar4) &&
         ((float)(iVar2 / 1000) < *(float *)(&DAT_00503fdc + param_1 * 0x11c))) {
        cVar1 = FUN_00417e90(param_1);
        iVar2 = DAT_0053be60;
        if (cVar1 == '\0') {
          iVar2 = (&DAT_005081b8)[param_1 * 0x1c];
        }
        if (0 < iVar2) {
          FUN_0040d9c0(param_1,iVar5 == iVar3);
          return 1;
        }
      }
    }
  }
  return 0;
}

