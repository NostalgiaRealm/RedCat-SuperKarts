/*
 * FUN_004405f0 at 004405f0
 * undefined4 __register FUN_004405f0(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 004405f0-00440620
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004405f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_4;
  local_8 = 0;
  if (param_1 != 0) {
    local_14 = param_2;
    local_10 = param_3;
    (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c),&local_14);
  }
  return local_8;
}

