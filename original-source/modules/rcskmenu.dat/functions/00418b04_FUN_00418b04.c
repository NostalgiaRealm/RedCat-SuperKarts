/*
 * FUN_00418b04 at 00418b04
 * undefined __register FUN_00418b04(int param_1)
 * Address ranges: 00418b04-00418b2f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418b04(int param_1)

{
  HGDIOBJ h;
  COLORREF color;
  
  h = (HGDIOBJ)FUN_004176e4(*(int *)(param_1 + 0xc));
  SelectObject(*(HDC *)(param_1 + 4),h);
  color = FUN_00417210(*(uint *)(*(int *)(param_1 + 0xc) + 0x18));
  SetTextColor(*(HDC *)(param_1 + 4),color);
  return;
}

