/*
 * FUN_00417fbc at 00417fbc
 * undefined __register FUN_00417fbc(int * param_1, char param_2)
 * Address ranges: 00417fbc-00417fee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417fbc(int *param_1,char param_2)

{
  byte abStack_18 [4];
  undefined4 local_14;
  char local_c;
  
  FUN_00417e04((int)param_1,(undefined4 *)abStack_18);
  if (param_2 == '\x01') {
    local_14 = 0xffffff;
  }
  local_c = param_2;
  FUN_00417e24(param_1,abStack_18);
  return;
}

