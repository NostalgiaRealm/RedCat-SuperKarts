/*
 * FUN_00456154 at 00456154
 * undefined FUN_00456154(void)
 * Address ranges: 00456154-00456181
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00456154(int param_1,int *param_2)

{
  int extraout_ECX;
  
  FUN_00455fb8(param_1);
  FUN_004118e8(param_2,param_1 + 0x2c,4);
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_00455fe4(param_1,param_2,extraout_ECX);
  }
  return;
}

