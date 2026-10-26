/*
 * FUN_00414154 at 00414154
 * undefined __register FUN_00414154(uint param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00414154-004141a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414154(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 local_104 [64];
  
  while (0 < (int)param_1) {
    if ((int)param_1 < 0x101) {
      FUN_0041292c(*(int *)(param_4 + -4),local_104,param_1);
      param_1 = 0;
    }
    else {
      FUN_0041292c(*(int *)(param_4 + -4),local_104,0x100);
      param_1 = param_1 - 0x100;
    }
  }
  return;
}

