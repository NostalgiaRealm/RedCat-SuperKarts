/*
 * FUN_0041335c at 0041335c
 * int __register FUN_0041335c(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 0041335c-0041339d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0041335c(int param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  uint extraout_ECX;
  undefined4 extraout_EDX;
  int local_c [2];
  
  cVar1 = FUN_00412910(param_1,param_2,param_3);
  if (cVar1 == '\x13') {
    FUN_004140d0(param_1,extraout_EDX,extraout_ECX);
    FUN_0041292c(param_1,local_c,8);
  }
  else {
    local_c[0] = FUN_004132f0(param_1,extraout_EDX,extraout_ECX);
  }
  return local_c[0];
}

