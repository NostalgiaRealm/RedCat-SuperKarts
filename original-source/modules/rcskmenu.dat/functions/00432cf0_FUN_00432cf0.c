/*
 * FUN_00432cf0 at 00432cf0
 * undefined __register FUN_00432cf0(int param_1)
 * Address ranges: 00432cf0-00432d0e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432cf0(int param_1)

{
  if (*(ushort *)(param_1 + 0x7a) != 0) {
    KillTimer((HWND)0x0,(uint)*(ushort *)(param_1 + 0x7a));
    *(undefined2 *)(param_1 + 0x7a) = 0;
  }
  return;
}

