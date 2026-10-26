/*
 * FUN_004131b0 at 004131b0
 * undefined __register FUN_004131b0(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 004131b0-004131ee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004131b0(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 local_10 [3];
  
  uVar1 = FUN_004140d0(param_1,param_2,param_3);
  if ((char)uVar1 == '\x11') {
    FUN_0041292c(param_1,local_10,8);
  }
  else {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    FUN_004132f0(param_1,extraout_EDX,extraout_ECX);
  }
  return;
}

