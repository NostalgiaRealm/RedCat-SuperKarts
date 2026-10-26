/*
 * FUN_0041bbc4 at 0041bbc4
 * undefined __register FUN_0041bbc4(int * param_1)
 * Address ranges: 0041bbc4-0041bc57;0041bc5f-0041bc62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041bbc4(int *param_1)

{
  HDC hdc;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  if (param_1[1] != 0) {
    puStack_10 = (undefined1 *)0x41bbe1;
    FUN_004185e8((int)param_1);
    puStack_14 = &LAB_0041bc58;
    uStack_18 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_18;
    puStack_10 = &stack0xfffffffc;
    if ((HGDIOBJ)param_1[0x17] != (HGDIOBJ)0x0) {
      puStack_10 = &stack0xfffffffc;
      SelectObject((HDC)param_1[1],(HGDIOBJ)param_1[0x17]);
    }
    if ((HPALETTE)param_1[0x18] != (HPALETTE)0x0) {
      SelectPalette((HDC)param_1[1],(HPALETTE)param_1[0x18],-1);
    }
    hdc = (HDC)param_1[1];
    FUN_00418a14(param_1,0);
    DeleteDC(hdc);
    FUN_0040fa84(DAT_0047b5dc,(int)param_1);
    *in_FS_OFFSET = uStack_18;
    puStack_10 = (undefined1 *)0x41bc5f;
    puStack_14 = (undefined1 *)0x41bc57;
    FUN_0041888c((int)param_1);
    return;
  }
  return;
}

