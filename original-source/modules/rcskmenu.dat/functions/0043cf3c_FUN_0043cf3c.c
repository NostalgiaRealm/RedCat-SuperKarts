/*
 * FUN_0043cf3c at 0043cf3c
 * undefined __register FUN_0043cf3c(int * param_1, undefined4 param_2, undefined4 param_3, char param_4, undefined4 param_5)
 * Address ranges: 0043cf3c-0043cf6d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043cf3c(int *param_1,undefined4 param_2,undefined4 param_3,char param_4,undefined4 param_5
                 )

{
  if (param_4 == '\0') {
    FUN_00403088((int *)param_1[0xe],param_2,param_3);
    param_2 = 0;
  }
  (**(code **)(*param_1 + 0x20))(param_1,param_2,param_3,param_5);
  return;
}

