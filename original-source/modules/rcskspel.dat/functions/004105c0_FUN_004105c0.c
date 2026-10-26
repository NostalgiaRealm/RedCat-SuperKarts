/*
 * FUN_004105c0 at 004105c0
 * undefined FUN_004105c0(void)
 * Address ranges: 004105c0-00410642
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004105c0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (DAT_0053be60 + -1 == param_1) {
    return DAT_0053be28;
  }
  iVar3 = 0;
  if (0 < DAT_00508610) {
    piVar4 = &DAT_005081b8;
    do {
      cVar1 = FUN_00417e90(iVar3);
      iVar2 = DAT_0053be60;
      if (cVar1 == '\0') {
        iVar2 = *piVar4;
      }
      if (iVar2 + -1 == param_1) {
        cVar1 = FUN_00417e90(iVar3);
        if (cVar1 != '\0') {
          return DAT_0053be28;
        }
        return (&DAT_005081bc)[iVar3 * 0x1c];
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0x1c;
    } while (iVar3 < DAT_00508610);
  }
  return 0xffffffff;
}

