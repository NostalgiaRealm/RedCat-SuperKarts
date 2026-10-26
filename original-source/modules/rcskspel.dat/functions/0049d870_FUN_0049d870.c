/*
 * FUN_0049d870 at 0049d870
 * undefined FUN_0049d870(void)
 * Address ranges: 0049d870-0049d89a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0049d870(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x38) != -1) {
    iVar1 = FUN_004b5400(*(int *)(param_1 + 0x38));
    if (iVar1 == *(int *)(param_1 + 0x40)) {
      uVar2 = FUN_0049d7d0();
      return uVar2 & 1;
    }
  }
  return 0;
}

