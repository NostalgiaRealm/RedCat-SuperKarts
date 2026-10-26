/*
 * FUN_00466208 at 00466208
 * undefined4 __register FUN_00466208(int param_1, undefined4 param_2)
 * Address ranges: 00466208-0046622f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00466208(int param_1,undefined4 param_2)

{
  undefined4 local_8;
  
  local_8 = param_2;
  if (*(short *)(param_1 + 0x23a) != 0) {
    (**(code **)(param_1 + 0x238))(*(undefined4 *)(param_1 + 0x23c),param_1,param_2,&local_8);
  }
  return local_8;
}

