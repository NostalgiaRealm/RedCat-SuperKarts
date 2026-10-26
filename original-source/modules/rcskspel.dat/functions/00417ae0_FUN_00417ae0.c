/*
 * FUN_00417ae0 at 00417ae0
 * undefined FUN_00417ae0(void)
 * Address ranges: 00417ae0-00417b5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417ae0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_28 [10];
  
  piVar5 = local_28;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  iVar3 = 0;
  local_28[DAT_0053be60] = 1;
  if (0 < DAT_00508610) {
    piVar5 = &DAT_005081b8;
    iVar4 = DAT_00508610;
    do {
      iVar6 = 0;
      if (0 < iVar4 + 1) {
        piVar2 = local_28;
        do {
          if (*piVar2 == 0) {
            cVar1 = FUN_00417e90(iVar3);
            iVar4 = DAT_00508610;
            piVar2 = &DAT_0053be60;
            if (cVar1 == '\0') {
              piVar2 = piVar5;
            }
            *piVar2 = iVar6;
            local_28[iVar6] = 1;
            break;
          }
          iVar6 = iVar6 + 1;
          piVar2 = piVar2 + 1;
        } while (iVar6 < iVar4 + 1);
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 0x1c;
    } while (iVar3 < iVar4);
  }
  return;
}

