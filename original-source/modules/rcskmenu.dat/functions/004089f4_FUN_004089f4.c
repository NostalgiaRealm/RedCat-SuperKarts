/*
 * FUN_004089f4 at 004089f4
 * byte * __register FUN_004089f4(byte * param_1, byte * param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 004089f4-00408a27
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte * FUN_004089f4(byte *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_00408340((char *)param_2);
  iVar1 = FUN_004085fc(param_1,(byte *)0x7fffffff,param_2,param_4,param_3,iVar1);
  param_1[iVar1] = 0;
  return param_1;
}

