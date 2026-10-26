/*
 * FUN_00414558 at 00414558
 * undefined FUN_00414558(void)
 * Address ranges: 00414558-0041457f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414558(int param_1,int *param_2,undefined4 *param_3)

{
  if (*(short *)(param_1 + 0x42) != 0) {
    (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),param_1,param_2,param_3);
  }
  (**(code **)(*param_2 + 0x18))(param_2,*param_3);
  return;
}

