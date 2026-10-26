/*
 * FUN_0041b530 at 0041b530
 * undefined FUN_0041b530(void)
 * Address ranges: 0041b530-0041b5a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b530(int *param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iStack_24;
  int iStack_1c;
  
  if (param_1[8] == 0) {
    FUN_0041b0b4((int)param_1);
  }
  iVar1 = param_1[8];
  if (*(short *)(iVar1 + 0x18) == 0) {
    if (*(HENHMETAFILE *)(iVar1 + 8) == (HENHMETAFILE)0x0) {
      *(int *)(iVar1 + 0x1c) = param_2;
    }
    else {
      GetEnhMetaFileHeader(*(HENHMETAFILE *)(iVar1 + 8),100,(LPENHMETAHEADER)&stack0xffffff94);
      iVar1 = MulDiv(param_2,iStack_1c * 100,iStack_24);
      FUN_0041b4f0(param_1,iVar1,extraout_ECX);
    }
  }
  else {
    iVar1 = MulDiv(param_2,0x9ec,DAT_0047d684);
    FUN_0041b4f0(param_1,iVar1,extraout_ECX_00);
  }
  return;
}

