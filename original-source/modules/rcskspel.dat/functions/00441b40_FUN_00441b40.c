/*
 * FUN_00441b40 at 00441b40
 * undefined FUN_00441b40(void)
 * Address ranges: 00441b40-00441c2f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441b40(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  if (param_1 != DAT_0053be28) {
    iVar6 = 0;
    if (0 < DAT_00508610) {
      piVar7 = &DAT_005081bc;
      do {
        cVar1 = FUN_00417e90(iVar6);
        iVar2 = DAT_0053be28;
        if (cVar1 == '\0') {
          iVar2 = *piVar7;
        }
        iVar5 = DAT_00508610;
        if (param_1 == iVar2) {
          cVar1 = FUN_00417e90(iVar6);
          iVar2 = DAT_0053be28;
          if (cVar1 == '\0') {
            iVar2 = *piVar7;
          }
          cVar1 = FUN_00417e90(iVar6);
          iVar5 = DAT_00508610;
          iVar3 = DAT_0053be28;
          if (cVar1 == '\0') {
            iVar3 = *piVar7;
          }
          if (*(int *)(iVar2 * 0xd0 + 0x1c + DAT_0067ee20) !=
              *(int *)(iVar3 * 0xd0 + 0x20 + DAT_0067ee20)) {
            cVar1 = DAT_0053bec4;
            if ((iVar6 < DAT_00508610) && (0x5081bb < (int)piVar7)) {
              cVar1 = (char)piVar7[0x16];
            }
            if ((DAT_00508610 <= iVar6) || (piVar4 = piVar7 + 0x16, (int)piVar7 < 0x5081bc)) {
              piVar4 = (int *)&DAT_0053bec4;
            }
            *(bool *)piVar4 = cVar1 == '\0';
          }
        }
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 0x1c;
      } while (iVar6 < iVar5);
    }
    return;
  }
  DAT_0053bec4 = DAT_0053bec4 == '\0';
  return;
}

