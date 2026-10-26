/*
 * FUN_0041af0c at 0041af0c
 * undefined FUN_0041af0c(void)
 * Address ranges: 0041af0c-0041af6c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0041af0c(int param_1)

{
  int iVar1;
  int iStack_1c;
  int iStack_14;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    FUN_0041b0b4(param_1);
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(short *)(iVar1 + 0x18) == 0) {
    if (*(HENHMETAFILE *)(iVar1 + 8) == (HENHMETAFILE)0x0) {
      iVar1 = *(int *)(iVar1 + 0x20);
    }
    else {
      GetEnhMetaFileHeader(*(HENHMETAFILE *)(iVar1 + 8),100,(LPENHMETAHEADER)&stack0xffffff98);
      iVar1 = MulDiv(*(int *)(iVar1 + 0x10),iStack_1c,iStack_14 * 100);
    }
  }
  else {
    iVar1 = MulDiv(*(int *)(iVar1 + 0x10),DAT_0047d684,0x9ec);
  }
  return iVar1;
}

