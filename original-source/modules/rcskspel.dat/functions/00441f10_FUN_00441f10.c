/*
 * FUN_00441f10 at 00441f10
 * undefined FUN_00441f10(void)
 * Address ranges: 00441f10-0044202a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00441f10(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  uVar1 = DAT_0053ba98;
  if (DAT_0053ba9c != 0) {
    if (param_1 == DAT_0053be28) {
      if (DAT_0053bec8 == '\0') {
        DAT_0053bec8 = 1;
        iVar3 = DAT_0053be2c * 0xac;
        DAT_0053becc = *(undefined4 *)(&DAT_00505bec + iVar3);
        DAT_0053bed0 = *(undefined4 *)(&DAT_00505bf0 + iVar3);
        *(undefined4 *)(&DAT_00505bec + iVar3) = DAT_0053ba98;
        *(undefined4 *)(&DAT_00505bf0 + iVar3) = uVar1;
        uVar1 = DAT_0053ba98;
        DAT_0053bed4 = *(undefined4 *)(&DAT_00505bd4 + iVar3);
        DAT_0053bed8 = *(undefined4 *)(&DAT_00505bd8 + iVar3);
        *(undefined4 *)(&DAT_00505bd4 + iVar3) = DAT_0053ba98;
        *(undefined4 *)(&DAT_00505bd8 + iVar3) = uVar1;
        return;
      }
    }
    else {
      iVar3 = 0;
      if (0 < DAT_00508610) {
        piVar5 = &DAT_005081bc;
        do {
          cVar2 = FUN_00417e90(iVar3);
          iVar4 = DAT_0053be28;
          if (cVar2 == '\0') {
            iVar4 = *piVar5;
          }
          if ((param_1 == iVar4) && ((char)piVar5[0x18] == '\0')) {
            *(undefined1 *)(piVar5 + 0x18) = 1;
            cVar2 = FUN_00417e90(iVar3);
            iVar4 = DAT_0053be28;
            if (cVar2 == '\0') {
              iVar4 = *piVar5;
            }
            *(undefined4 *)(iVar4 * 0xd0 + 0xa4 + DAT_0067ee20) = _DAT_0053ba94;
          }
          iVar3 = iVar3 + 1;
          piVar5 = piVar5 + 0x1c;
        } while (iVar3 < DAT_00508610);
      }
    }
  }
  return;
}

