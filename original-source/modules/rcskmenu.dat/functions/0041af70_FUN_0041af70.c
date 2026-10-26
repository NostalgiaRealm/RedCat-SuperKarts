/*
 * FUN_0041af70 at 0041af70
 * undefined FUN_0041af70(void)
 * Address ranges: 0041af70-0041aff8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041af70(int param_1)

{
  int iVar1;
  UINT nNumEntries;
  HPALETTE pHVar2;
  undefined4 uVar3;
  LOGPALETTE aLStack_410 [128];
  
  uVar3 = 0;
  iVar1 = *(int *)(param_1 + 0x20);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {
    if (*(int *)(iVar1 + 0x14) == 0) {
      nNumEntries = GetEnhMetaFilePaletteEntries(*(HENHMETAFILE *)(iVar1 + 8),0,(LPPALETTEENTRY)0x0)
      ;
      if (nNumEntries == 0) {
        return 0;
      }
      if (0x100 < (int)nNumEntries) {
        nNumEntries = nNumEntries & 0xff;
      }
      FUN_00416a28(*(HGDIOBJ *)(*(int *)(param_1 + 0x20) + 0x14));
      aLStack_410[0].palVersion = 0x300;
      aLStack_410[0].palNumEntries = (WORD)nNumEntries;
      GetEnhMetaFilePaletteEntries
                (*(HENHMETAFILE *)(*(int *)(param_1 + 0x20) + 8),nNumEntries,
                 aLStack_410[0].palPalEntry);
      pHVar2 = CreatePalette(aLStack_410);
      *(HPALETTE *)(*(int *)(param_1 + 0x20) + 0x14) = pHVar2;
    }
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x14);
  }
  return uVar3;
}

