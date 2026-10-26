/*
 * FUN_004718b4 at 004718b4
 * int __register FUN_004718b4(int * param_1)
 * Address ranges: 004718b4-004718de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004718b4(int *param_1)

{
  char cVar1;
  
  cVar1 = FUN_00472c1c();
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xb5) = 8;
    return param_1[0x8d];
  }
  FUN_0042ed80(param_1);
  return 1;
}

