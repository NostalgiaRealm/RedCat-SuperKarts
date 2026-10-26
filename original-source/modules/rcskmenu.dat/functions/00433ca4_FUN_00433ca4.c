/*
 * FUN_00433ca4 at 00433ca4
 * int __register FUN_00433ca4(int * param_1)
 * Address ranges: 00433ca4-00433cca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00433ca4(int *param_1)

{
  bool bVar1;
  HIMAGELIST himl;
  COLORREF CVar2;
  int iVar3;
  
  bVar1 = FUN_00433874((int)param_1);
  if (bVar1) {
    himl = (HIMAGELIST)FUN_004339b0(param_1);
    CVar2 = ImageList_GetBkColor(himl);
    iVar3 = FUN_004336e4(CVar2);
    return iVar3;
  }
  return param_1[0xe];
}

