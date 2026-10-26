/*
 * FUN_00413124 at 00413124
 * undefined __register FUN_00413124(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 00413124-00413161
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413124(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 local_c [2];
  
  uVar1 = FUN_004140d0(param_1,param_2,param_3);
  if ((char)uVar1 == '\x0f') {
    FUN_0041292c(param_1,local_c,4);
  }
  else {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    FUN_004132f0(param_1,extraout_EDX,extraout_ECX);
  }
  return;
}

