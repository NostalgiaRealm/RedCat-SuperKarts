/*
 * FUN_00411680 at 00411680
 * undefined FUN_00411680(void)
 * Address ranges: 00411680-004116ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00411680(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 * 0x50 + 0x24 + DAT_00680ae0)) {
    do {
      iVar1 = FUN_004944a0(iVar2);
      if (*(int *)(iVar1 * 0xd0 + 0x44 + DAT_0067ee20) == 1) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 * 0x50 + 0x24 + DAT_00680ae0));
  }
  return 1;
}

