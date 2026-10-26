/*
 * FUN_0041b440 at 0041b440
 * undefined FUN_0041b440(void)
 * Address ranges: 0041b440-0041b4b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b440(int *param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iStack_20;
  int iStack_18;
  
  if (param_1[8] == 0) {
    FUN_0041b0b4((int)param_1);
  }
  iVar1 = param_1[8];
  if (*(short *)(iVar1 + 0x18) == 0) {
    if (*(HENHMETAFILE *)(iVar1 + 8) == (HENHMETAFILE)0x0) {
      *(int *)(iVar1 + 0x20) = param_2;
    }
    else {
      GetEnhMetaFileHeader(*(HENHMETAFILE *)(iVar1 + 8),100,(LPENHMETAHEADER)&stack0xffffff94);
      iVar1 = MulDiv(param_2,iStack_18 * 100,iStack_20);
      FUN_0041b4b4(param_1,iVar1,extraout_ECX);
    }
  }
  else {
    iVar1 = MulDiv(param_2,0x9ec,DAT_0047d684);
    FUN_0041b4b4(param_1,iVar1,extraout_ECX_00);
  }
  return;
}

