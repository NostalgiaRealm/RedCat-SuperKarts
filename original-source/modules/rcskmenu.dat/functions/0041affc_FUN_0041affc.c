/*
 * FUN_0041affc at 0041affc
 * undefined FUN_0041affc(void)
 * Address ranges: 0041affc-0041b05c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0041affc(int param_1)

{
  int iVar1;
  int iStack_20;
  int iStack_18;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    FUN_0041b0b4(param_1);
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(short *)(iVar1 + 0x18) == 0) {
    if (*(HENHMETAFILE *)(iVar1 + 8) == (HENHMETAFILE)0x0) {
      iVar1 = *(int *)(iVar1 + 0x1c);
    }
    else {
      GetEnhMetaFileHeader(*(HENHMETAFILE *)(iVar1 + 8),100,(LPENHMETAHEADER)&stack0xffffff98);
      iVar1 = MulDiv(*(int *)(iVar1 + 0xc),iStack_20,iStack_18 * 100);
    }
  }
  else {
    iVar1 = MulDiv(*(int *)(iVar1 + 0xc),DAT_0047d684,0x9ec);
  }
  return iVar1;
}

