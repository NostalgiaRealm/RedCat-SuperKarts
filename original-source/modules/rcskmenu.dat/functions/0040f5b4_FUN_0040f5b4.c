/*
 * FUN_0040f5b4 at 0040f5b4
 * undefined __register FUN_0040f5b4(undefined4 param_1, byte * param_2, undefined4 param_3)
 * Address ranges: 0040f5b4-0040f5e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f5b4(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined1 local_c;
  
  FUN_0040f5b0();
  local_c = 0;
  local_10 = param_3;
  uVar1 = FUN_0040aca0((int)&DAT_0040dc44,'\x01',param_2,0,&local_10);
  FUN_00403604(uVar1);
  return;
}

