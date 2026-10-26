/*
 * FUN_004348e4 at 004348e4
 * undefined __register FUN_004348e4(int * param_1, int param_2)
 * Address ranges: 004348e4-00434954
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004348e4(int *param_1,int param_2)

{
  IStream *pIVar1;
  IStream *pstm;
  HIMAGELIST himl;
  BOOL BVar2;
  int *piVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x4348fb;
  pIVar1 = (IStream *)FUN_004151c4((int *)&PTR_FUN_0040e784,'\x01',param_2,0);
  puStack_14 = &LAB_00434955;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  pstm = pIVar1;
  if (pIVar1 != (IStream *)0x0) {
    pstm = pIVar1 + 5;
  }
  himl = (HIMAGELIST)FUN_004339b0(param_1);
  BVar2 = ImageList_Write(himl,pstm);
  if (BVar2 == 0) {
    piVar3 = FUN_0040ad20((int *)&DAT_0040db34,'\x01',(undefined4 *)PTR_PTR_0047c764);
    FUN_00403604(piVar3);
  }
  *in_FS_OFFSET = uStack_18;
  puStack_14 = (undefined1 *)0x434954;
  FUN_00402eac((int *)pIVar1);
  return;
}

