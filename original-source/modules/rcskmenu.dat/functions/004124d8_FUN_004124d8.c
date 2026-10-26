/*
 * FUN_004124d8 at 004124d8
 * int __register FUN_004124d8(char * param_1, byte * param_2)
 * Address ranges: 004124d8-004124ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004124d8(char *param_1,byte *param_2)

{
  int iVar1;
  
  iVar1 = FUN_0040d2ac(param_1,param_2);
  if (iVar1 == -1) {
    FUN_004124c0();
  }
  return iVar1;
}

