/*
 * FUN_00466220 at 00466220
 * undefined FUN_00466220(void)
 * Address ranges: 00466220-00466254
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00466220(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0044ff80();
  if (*(int *)(param_1 + 0x3c) == iVar1) {
    iVar1 = FUN_004500b0();
    if (*(int *)(param_1 + 0x40) == iVar1) {
      iVar1 = FUN_004503c0();
      if (*(int *)(param_1 + 0x48) == iVar1) {
        return 1;
      }
    }
  }
  return 0;
}

