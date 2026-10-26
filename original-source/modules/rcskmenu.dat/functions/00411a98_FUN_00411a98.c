/*
 * FUN_00411a98 at 00411a98
 * undefined __register FUN_00411a98(int * param_1, undefined4 param_2)
 * Address ranges: 00411a98-00411ab5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411a98(int *param_1,undefined4 param_2)

{
  BOOL BVar1;
  
  (**(code **)(*param_1 + 0xc))(param_1,param_2,0);
  BVar1 = SetEndOfFile((HANDLE)param_1[1]);
  FUN_0040bdf0(BVar1);
  return;
}

