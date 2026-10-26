/*
 * FUN_0042f8b0 at 0042f8b0
 * undefined FUN_0042f8b0(void)
 * Address ranges: 0042f8b0-0042f8eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f8b0(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar3;
  
  FUN_00444c5c(param_1);
  if ((*(byte *)(param_1 + 8) & 8) == 0) {
    iVar1 = FUN_0044401c((int)param_1);
    if (-1 < iVar1 + -1) {
      iVar3 = 0;
      do {
        piVar2 = (int *)FUN_00444030((int)param_1,iVar3);
        FUN_0043f564(piVar2,CONCAT31((int3)((uint)extraout_EDX >> 8),
                                     *(undefined1 *)((int)param_1 + 0x47)),extraout_ECX);
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

