/*
 * FUN_0041cce0 at 0041cce0
 * undefined __register FUN_0041cce0(int param_1)
 * Address ranges: 0041cce0-0041cd42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041cce0(int param_1)

{
  int iVar1;
  HPALETTE pHVar2;
  BOOL BVar3;
  
  iVar1 = *(int *)(param_1 + 0x20);
  if (1 < *(int *)(iVar1 + 4)) {
    FUN_0041cf14(param_1);
    if (*(char *)(iVar1 + 0x71) == '\0') {
      pHVar2 = *(HPALETTE *)(iVar1 + 0x10);
    }
    else {
      pHVar2 = (HPALETTE)0x0;
    }
    FUN_0041c984(param_1,*(HBITMAP *)(iVar1 + 8),pHVar2,(undefined4 *)(iVar1 + 0x18));
    return;
  }
  if ((*(int *)(iVar1 + 8) != 0) && (*(int *)(iVar1 + 8) != *(int *)(iVar1 + 0x14))) {
    if (*(HGDIOBJ *)(iVar1 + 0x14) != (HGDIOBJ)0x0) {
      BVar3 = DeleteObject(*(HGDIOBJ *)(iVar1 + 0x14));
      if (BVar3 == 0) {
        FUN_00418ce4();
      }
    }
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
  }
  return;
}

