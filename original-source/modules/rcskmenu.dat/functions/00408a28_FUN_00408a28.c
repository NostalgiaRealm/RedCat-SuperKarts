/*
 * FUN_00408a28 at 00408a28
 * byte * __register FUN_00408a28(byte * param_1, byte * param_2, byte * param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 00408a28-00408a5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte * FUN_00408a28(byte *param_1,byte *param_2,byte *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_00408340((char *)param_3);
  iVar1 = FUN_004085fc(param_1,param_2,param_3,param_4,param_5,iVar1);
  param_1[iVar1] = 0;
  return param_1;
}

