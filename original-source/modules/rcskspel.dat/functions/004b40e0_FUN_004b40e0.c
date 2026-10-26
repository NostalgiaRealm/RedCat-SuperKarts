/*
 * FUN_004b40e0 at 004b40e0
 * undefined FUN_004b40e0(void)
 * Address ranges: 004b40e0-004b4122
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b40e0(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_006ab7b4 != 0) {
    iVar1 = 0;
    if (0 < DAT_006ab78c) {
      iVar2 = 0;
      do {
        if (*(int *)(iVar2 + 0x30 + DAT_006ab798) != 0) {
          FUN_004b3fd0(iVar1);
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x44;
      } while (iVar1 < DAT_006ab78c);
    }
    return 0;
  }
  return 0;
}

