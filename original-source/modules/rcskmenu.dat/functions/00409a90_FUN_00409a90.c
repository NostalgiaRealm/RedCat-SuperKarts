/*
 * FUN_00409a90 at 00409a90
 * undefined __register FUN_00409a90(int * param_1, byte * param_2, undefined1 * param_3)
 * Address ranges: 00409a90-00409ae4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409a90(int *param_1,byte *param_2,undefined1 *param_3)

{
  undefined4 local_104 [64];
  
  if (param_2 == (byte *)0x0) {
    FUN_0040931c(&DAT_00409ae8,0,param_3,&stack0xfffffffc);
  }
  else {
    FUN_0040931c(param_2,param_2,param_3,&stack0xfffffffc);
  }
  FUN_00403c38(param_1,local_104,0);
  return;
}

