/*
 * FUN_004507d8 at 004507d8
 * int * __register FUN_004507d8(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 004507d8-004507f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004507d8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_0047d8f4 == (int *)0x0) {
    DAT_0047d8f4 = FUN_004505fc((int *)&LAB_004505a8,'\x01',param_3);
  }
  return DAT_0047d8f4;
}

