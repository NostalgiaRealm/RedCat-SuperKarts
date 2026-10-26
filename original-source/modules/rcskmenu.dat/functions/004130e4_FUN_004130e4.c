/*
 * FUN_004130e4 at 004130e4
 * undefined __register FUN_004130e4(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 004130e4-00413122
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004130e4(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 local_14 [4];
  
  uVar1 = FUN_004140d0(param_1,param_2,param_3);
  if ((char)uVar1 == '\x05') {
    FUN_0041292c(param_1,local_14,10);
  }
  else {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    FUN_004132f0(param_1,extraout_EDX,extraout_ECX);
  }
  return;
}

