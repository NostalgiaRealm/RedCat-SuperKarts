/*
 * FUN_00418b60 at 00418b60
 * undefined __register FUN_00418b60(int param_1)
 * Address ranges: 00418b60-00418bd8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418b60(int param_1)

{
  HGDIOBJ pvVar1;
  undefined4 uVar2;
  uint uVar3;
  COLORREF color;
  
  pvVar1 = (HGDIOBJ)FUN_00417ed4(*(int *)(param_1 + 0x14));
  UnrealizeObject(pvVar1);
  pvVar1 = (HGDIOBJ)FUN_00417ed4(*(int *)(param_1 + 0x14));
  SelectObject(*(HDC *)(param_1 + 4),pvVar1);
  uVar2 = FUN_00417fb4(*(int *)(param_1 + 0x14));
  if ((char)uVar2 == '\0') {
    uVar3 = FUN_00417e98(*(int *)(param_1 + 0x14));
    color = FUN_00417210(uVar3);
    SetBkColor(*(HDC *)(param_1 + 4),color);
    SetBkMode(*(HDC *)(param_1 + 4),2);
    return;
  }
  uVar3 = FUN_00417e98(*(int *)(param_1 + 0x14));
  uVar3 = FUN_00417210(uVar3);
  SetBkColor(*(HDC *)(param_1 + 4),~uVar3);
  SetBkMode(*(HDC *)(param_1 + 4),1);
  return;
}

