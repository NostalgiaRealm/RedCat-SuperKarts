/*
 * FUN_00461858 at 00461858
 * undefined __register FUN_00461858(int param_1, char param_2, undefined4 param_3)
 * Address ranges: 00461858-004618cf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00461858(int param_1,char param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  
  *(char *)(param_1 + 0x354) = param_2;
  if (param_2 == '\0') {
    FUN_0043f564(*(int **)(param_1 + 0x348),0,param_3);
    FUN_0043f564(*(int **)(param_1 + 0x300),0,extraout_ECX);
    FUN_0043f564(*(int **)(param_1 + 0x2e0),0,extraout_ECX_00);
    FUN_0043ee6c(*(int **)(param_1 + 0x2dc),0x180);
    FUN_0043ee8c(*(int **)(param_1 + 0x2dc),0x19a);
    return;
  }
  if (param_2 == '\x01') {
    FUN_0043f564(*(int **)(param_1 + 0x344),0,param_3);
    FUN_0043f564(*(int **)(param_1 + 0x340),0,extraout_ECX_01);
  }
  return;
}

