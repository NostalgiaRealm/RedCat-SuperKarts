/*
 * FUN_004447b0 at 004447b0
 * undefined1 __register FUN_004447b0(int param_1, undefined1 param_2, undefined4 * param_3)
 * Address ranges: 004447b0-004447f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_004447b0(int param_1,undefined1 param_2,undefined4 *param_3)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined1 local_10 [4];
  
  local_18 = *param_3;
  uStack_14 = param_3[1];
  local_10[0] = 0;
  if (*(short *)(param_1 + 0x1d2) != 0) {
    (**(code **)(param_1 + 0x1d0))
              (*(undefined4 *)(param_1 + 0x1d4),param_1,param_2,local_10,&local_18);
  }
  return local_10[0];
}

