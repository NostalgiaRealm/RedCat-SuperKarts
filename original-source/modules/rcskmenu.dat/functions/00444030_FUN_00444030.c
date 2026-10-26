/*
 * FUN_00444030 at 00444030
 * undefined4 __register FUN_00444030(int param_1, int param_2)
 * Address ranges: 00444030-00444051
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00444030(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 0x140) == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x140),param_2);
  }
  return uVar1;
}

