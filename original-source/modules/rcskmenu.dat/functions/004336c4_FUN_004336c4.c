/*
 * FUN_004336c4 at 004336c4
 * int __register FUN_004336c4(uint param_1)
 * Address ranges: 004336c4-004336e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004336c4(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_00417210(param_1);
  if (iVar1 == 0x1fffffff) {
    return -1;
  }
  if (iVar1 == 0x20000000) {
    iVar1 = -0x1000000;
  }
  return iVar1;
}

