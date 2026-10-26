/*
 * FUN_0044903c at 0044903c
 * undefined __register FUN_0044903c(int param_1)
 * Address ranges: 0044903c-00449061
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044903c(int param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  if (*(int *)(param_1 + 0x6c) == 0) {
    iVar1 = FUN_0044401c(*(int *)(param_1 + 0x14));
    if (0 < iVar1) {
      FUN_00447930(param_1,0,extraout_ECX);
    }
  }
  return;
}

