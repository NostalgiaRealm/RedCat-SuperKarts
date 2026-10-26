/*
 * FUN_0040f960 at 0040f960
 * undefined FUN_0040f960(void)
 * Address ranges: 0040f960-0040f9c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0040f960(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  iVar1 = FUN_0044a5e0();
  if (0 < iVar1) {
    piVar4 = (int *)(param_1 + 0x1cc);
    do {
      if (DAT_00508610 <= iVar3) {
        return;
      }
      FUN_0044a700(iVar2);
      iVar1 = FUN_0044cab0();
      if (iVar1 != -1) {
        FUN_0040f520(iVar1);
        *piVar4 = iVar1;
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = FUN_0044a5e0();
    } while (iVar2 < iVar1);
  }
  return;
}

