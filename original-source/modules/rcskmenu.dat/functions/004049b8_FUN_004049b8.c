/*
 * FUN_004049b8 at 004049b8
 * bool __register FUN_004049b8(undefined4 param_1, short * param_2, undefined4 param_3)
 * Address ranges: 004049b8-004049cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_004049b8(undefined4 param_1,short *param_2,undefined4 param_3)

{
  short sVar1;
  
  sVar1 = *param_2;
  if (sVar1 == 0x101) {
    FUN_0040494c(param_1,(undefined4 *)param_2,param_3);
  }
  return sVar1 == 0x101;
}

