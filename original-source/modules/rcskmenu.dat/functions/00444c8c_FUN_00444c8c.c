/*
 * FUN_00444c8c at 00444c8c
 * undefined __register FUN_00444c8c(int param_1)
 * Address ranges: 00444c8c-00444cb3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444c8c(int param_1)

{
  SetWindowPos(*(HWND *)(param_1 + 0x14c),(HWND)0x0,0,0,0,0,
               (uint)*(ushort *)(&DAT_0047b9bc + (uint)*(byte *)(param_1 + 0x168) * 2));
  return;
}

