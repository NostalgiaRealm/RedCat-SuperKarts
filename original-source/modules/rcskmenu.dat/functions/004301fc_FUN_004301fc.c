/*
 * FUN_004301fc at 004301fc
 * undefined __register FUN_004301fc(int param_1)
 * Address ranges: 004301fc-00430246
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004301fc(int param_1)

{
  if ((*(int *)(param_1 + 0x5c) != *(int *)(param_1 + 0x68)) &&
     (*(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x5c), *(short *)(param_1 + 0x92) != 0)) {
    (**(code **)(param_1 + 0x90))(*(undefined4 *)(param_1 + 0x94),param_1);
  }
  if ((*(int *)(param_1 + 0x58) != *(int *)(param_1 + 100)) &&
     (*(int *)(param_1 + 100) = *(int *)(param_1 + 0x58), *(short *)(param_1 + 0x8a) != 0)) {
    (**(code **)(param_1 + 0x88))(*(undefined4 *)(param_1 + 0x8c),param_1);
  }
  return;
}

