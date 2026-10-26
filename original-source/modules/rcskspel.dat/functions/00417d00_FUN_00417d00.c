/*
 * FUN_00417d00 at 00417d00
 * undefined FUN_00417d00(void)
 * Address ranges: 00417d00-00417dce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417d00(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_4;
  
  local_4 = 0;
  iVar1 = DAT_00508610;
  if (0 < DAT_00508610) {
    piVar4 = &DAT_005081b4;
    piVar3 = &DAT_00503ef0;
    do {
      if (piVar4[3] == 0) {
        iVar1 = *piVar3;
        piVar4[3] = 1;
        FUN_00417e30(iVar1);
        iVar1 = DAT_0053be70 -
                *(int *)(DAT_00504f98 + 0x60 + *(int *)(*piVar3 * 0xd0 + 0x10 + DAT_0067ee20) * 0x6c
                        );
        *piVar4 = (*piVar4 / (DAT_00680b2c * DAT_0053ba1c - iVar1)) * iVar1 + *piVar4;
        iVar1 = DAT_00508610;
      }
      piVar3 = piVar3 + 0x47;
      local_4 = local_4 + 1;
      piVar4 = piVar4 + 0x1c;
    } while (local_4 < iVar1);
  }
  if (1 < iVar1 + 1) {
    piVar3 = &DAT_00508224;
    iVar2 = DAT_005081b4;
    do {
      if (iVar2 == *piVar3) {
        iVar2 = *piVar3 + 1;
        DAT_005081b4 = iVar2;
      }
      piVar3 = piVar3 + 0x1c;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

