/*
 * FUN_00447040 at 00447040
 * bool __register FUN_00447040(int param_1)
 * Address ranges: 00447040-00447084
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00447040(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = FUN_00433874(param_1);
  if ((bVar1) && (*(char *)(param_1 + 0x62) != '\0')) {
    iVar2 = FUN_00446fa8(param_1);
    ImageList_EndDrag();
    bVar1 = iVar2 != 0;
    *(undefined1 *)(param_1 + 0x62) = 0;
    FUN_00446ecc(param_1,-1);
    ShowCursor(-1);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

