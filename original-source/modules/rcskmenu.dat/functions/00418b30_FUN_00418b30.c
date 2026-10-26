/*
 * FUN_00418b30 at 00418b30
 * undefined __register FUN_00418b30(int param_1)
 * Address ranges: 00418b30-00418b5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418b30(int param_1)

{
  HGDIOBJ h;
  
  h = (HGDIOBJ)FUN_00417be4(*(int *)(param_1 + 0x10));
  SelectObject(*(HDC *)(param_1 + 4),h);
  SetROP2(*(HDC *)(param_1 + 4),
          (uint)*(ushort *)(&DAT_0047b5b4 + (uint)*(byte *)(*(int *)(param_1 + 0x10) + 0x18) * 2));
  return;
}

