/*
 * FUN_00454f20 at 00454f20
 * int * __register FUN_00454f20(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00454f20-00454f3f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00454f20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_0047d920 == (int *)0x0) {
    DAT_0047d920 = FUN_00454eac((int *)&DAT_00454e9c,'\x01',param_3);
  }
  return DAT_0047d920;
}

