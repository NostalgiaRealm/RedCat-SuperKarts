/*
 * FUN_0041252c at 0041252c
 * undefined __register FUN_0041252c(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 0041252c-0041254e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041252c(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint extraout_ECX;
  undefined4 extraout_EDX;
  
  uVar1 = FUN_004140d0(param_1,param_2,param_3);
  if ((char)param_2 != (char)uVar1) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    FUN_00414230(param_1,extraout_EDX,extraout_ECX);
    FUN_004124c0();
  }
  return;
}

