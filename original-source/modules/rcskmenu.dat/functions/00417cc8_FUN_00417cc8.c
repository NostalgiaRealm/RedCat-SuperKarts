/*
 * FUN_00417cc8 at 00417cc8
 * undefined __register FUN_00417cc8(int * param_1, int param_2)
 * Address ranges: 00417cc8-00417cf0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417cc8(int *param_1,int param_2)

{
  byte abStack_18 [8];
  int local_10;
  
  if (-1 < param_2) {
    FUN_00417b4c((int)param_1,(undefined4 *)abStack_18);
    local_10 = param_2;
    FUN_00417b64(param_1,abStack_18);
  }
  return;
}

