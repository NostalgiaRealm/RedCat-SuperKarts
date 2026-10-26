/*
 * FUN_00442030 at 00442030
 * undefined FUN_00442030(void)
 * Address ranges: 00442030-004420ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442030(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  uVar1 = DAT_0053bed0;
  if (DAT_0053ba9c != 0) {
    if (param_1 == DAT_0053be28) {
      if (DAT_0053bec8 != '\0') {
        DAT_0053bec8 = 0;
        iVar4 = DAT_0053be2c * 0xac;
        *(undefined4 *)(&DAT_00505bec + iVar4) = DAT_0053becc;
        uVar2 = DAT_0053bed4;
        *(undefined4 *)(&DAT_00505bf0 + iVar4) = uVar1;
        uVar1 = DAT_0053bed8;
        *(undefined4 *)(&DAT_00505bd4 + iVar4) = uVar2;
        *(undefined4 *)(&DAT_00505bd8 + iVar4) = uVar1;
        return;
      }
    }
    else {
      iVar4 = 0;
      if (0 < DAT_00508610) {
        pcVar6 = &DAT_0050821c;
        do {
          cVar3 = FUN_00417e90(iVar4);
          iVar5 = DAT_0053be28;
          if (cVar3 == '\0') {
            iVar5 = *(int *)(pcVar6 + -0x60);
          }
          if ((param_1 == iVar5) && (*pcVar6 != '\0')) {
            *pcVar6 = '\0';
          }
          iVar4 = iVar4 + 1;
          pcVar6 = pcVar6 + 0x70;
        } while (iVar4 < DAT_00508610);
      }
    }
  }
  return;
}

