/*
 * FUN_004141a8 at 004141a8
 * undefined __register FUN_004141a8(undefined4 param_1, undefined4 param_2, uint param_3, int param_4)
 * Address ranges: 004141a8-004141ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004141a8(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint local_8;
  
  local_8 = param_3;
  FUN_0041292c(*(int *)(param_4 + -4),&local_8,4);
  FUN_00414154(local_8,extraout_EDX,extraout_ECX,param_4);
  return;
}

