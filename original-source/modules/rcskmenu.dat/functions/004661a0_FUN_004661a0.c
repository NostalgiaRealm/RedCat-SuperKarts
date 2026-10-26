/*
 * FUN_004661a0 at 004661a0
 * undefined __register FUN_004661a0(int param_1, undefined4 param_2, RECT * param_3, undefined1 param_4)
 * Address ranges: 004661a0-004661d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004661a0(int param_1,undefined4 param_2,RECT *param_3,undefined1 param_4)

{
  if (*(short *)(param_1 + 0x232) == 0) {
    FUN_00418538(*(int **)(param_1 + 0x1f0),param_3);
  }
  else {
    (**(code **)(param_1 + 0x230))(*(undefined4 *)(param_1 + 0x234),param_1,param_2,param_4,param_3)
    ;
  }
  return;
}

