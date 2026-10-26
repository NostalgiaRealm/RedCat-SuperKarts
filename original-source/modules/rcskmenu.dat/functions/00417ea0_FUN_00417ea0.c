/*
 * FUN_00417ea0 at 00417ea0
 * undefined __register FUN_00417ea0(int * param_1, undefined4 param_2)
 * Address ranges: 00417ea0-00417ed0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417ea0(int *param_1,undefined4 param_2)

{
  byte abStack_18 [4];
  undefined4 local_14;
  char local_c;
  
  FUN_00417e04((int)param_1,(undefined4 *)abStack_18);
  if (local_c == '\x01') {
    local_c = '\0';
  }
  local_14 = param_2;
  FUN_00417e24(param_1,abStack_18);
  return;
}

