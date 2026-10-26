/*
 * FUN_00442970 at 00442970
 * undefined FUN_00442970(void)
 * Address ranges: 00442970-004429e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00442970(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1 == DAT_0053be28) {
    _DAT_0053be6c = 1;
  }
  iVar3 = 0;
  if (0 < DAT_00508610) {
    piVar4 = &DAT_005081bc;
    while( true ) {
      cVar1 = FUN_00417e90(iVar3);
      iVar2 = DAT_0053be28;
      if (cVar1 == '\0') {
        iVar2 = *piVar4;
      }
      if (iVar2 == param_1) break;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0x1c;
      if (DAT_00508610 <= iVar3) {
        return;
      }
    }
    (&DAT_005081c4)[iVar3 * 0x1c] = (uint)((&DAT_005081c4)[iVar3 * 0x1c] == 0);
  }
  return;
}

