/*
 * FUN_0044243d at 0044243d
 * bool __register FUN_0044243d(int param_1, int param_2)
 * Address ranges: 0044243a-0044244a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0044243d(int param_1,int param_2)

{
  for (; (param_2 != 0 && (param_1 != param_2)); param_2 = *(int *)(param_2 + 0x24)) {
  }
  return param_2 != 0;
}

