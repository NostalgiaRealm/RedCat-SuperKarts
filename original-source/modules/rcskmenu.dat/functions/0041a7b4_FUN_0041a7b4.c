/*
 * FUN_0041a7b4 at 0041a7b4
 * int * __register FUN_0041a7b4(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 0041a7b4-0041a7d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0041a7b4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_0047b5d4 == (int *)0x0) {
    DAT_0047b5d4 = FUN_0041a638((int *)&DAT_0041a624,'\x01',param_3);
  }
  return DAT_0047b5d4;
}

