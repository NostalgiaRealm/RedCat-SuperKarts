/*
 * FUN_004108b8 at 004108b8
 * undefined __register FUN_004108b8(undefined4 param_1, byte * param_2, undefined4 param_3)
 * Address ranges: 004108b8-004108e9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004108b8(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined1 local_c;
  
  FUN_004108b4();
  local_c = 0;
  local_10 = param_3;
  uVar1 = FUN_0040aca0((int)&DAT_0040dcf4,'\x01',param_2,0,&local_10);
  FUN_00403604(uVar1);
  return;
}

