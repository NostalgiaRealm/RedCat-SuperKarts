/*
 * FUN_00433bb0 at 00433bb0
 * int __register FUN_00433bb0(int * param_1)
 * Address ranges: 00433bb0-00433bd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00433bb0(int *param_1)

{
  bool bVar1;
  HIMAGELIST himl;
  int iVar2;
  
  bVar1 = FUN_00433874((int)param_1);
  if (bVar1) {
    himl = (HIMAGELIST)FUN_004339b0(param_1);
    iVar2 = ImageList_GetImageCount(himl);
    return iVar2;
  }
  return 0;
}

