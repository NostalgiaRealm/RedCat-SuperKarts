/*
 * FUN_0045dfa8 at 0045dfa8
 * undefined __register FUN_0045dfa8(int * param_1, char param_2)
 * Address ranges: 0045dfa8-0045dfe8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045dfa8(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_00402eac((int *)piVar1[0x80]);
  FUN_0045dfec((int)piVar1,0);
  piVar1[0x85] = 0;
  FUN_004418ac(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

