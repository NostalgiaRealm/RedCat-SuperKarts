/*
 * FUN_004240d4 at 004240d4
 * undefined __register FUN_004240d4(int param_1)
 * Address ranges: 004240d4-004240f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004240d4(int param_1)

{
  FUN_0043f2b8(param_1);
  if (*(short *)(param_1 + 0x202) != 0) {
    (**(code **)(param_1 + 0x200))(*(undefined4 *)(param_1 + 0x204),param_1);
  }
  return;
}

