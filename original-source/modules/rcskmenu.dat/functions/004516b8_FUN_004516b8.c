/*
 * FUN_004516b8 at 004516b8
 * int * __register FUN_004516b8(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 004516b8-004516e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004516b8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_0047d8f8 == (int *)0x0) {
    DAT_0047d8f8 = FUN_004507f8((int *)&PTR_FUN_004501d8,'\x01',param_3);
    FUN_0041bd50((int)DAT_0047d8f8);
  }
  return DAT_0047d8f8;
}

