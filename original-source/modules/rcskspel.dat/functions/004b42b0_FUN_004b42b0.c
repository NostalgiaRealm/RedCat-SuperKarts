/*
 * FUN_004b42b0 at 004b42b0
 * undefined FUN_004b42b0(void)
 * Address ranges: 004b42b0-004b4303
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004b42b0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_006ab78c) {
    iVar1 = 0;
    do {
      if ((*(int *)(iVar1 + 0x34 + DAT_006ab798) == param_1) &&
         (*(int *)(iVar1 + 0x30 + DAT_006ab798) == 0)) {
        return iVar2;
      }
      FUN_004afce0(s__d_used__d_005005a8,iVar2,*(undefined4 *)(iVar1 + 0x30 + DAT_006ab798));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x44;
    } while (iVar2 < DAT_006ab78c);
  }
  return -1;
}

