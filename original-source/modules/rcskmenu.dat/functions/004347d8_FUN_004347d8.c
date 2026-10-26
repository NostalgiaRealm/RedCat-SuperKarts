/*
 * FUN_004347d8 at 004347d8
 * undefined __register FUN_004347d8(int * param_1, int param_2)
 * Address ranges: 004347d8-00434850
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004347d8(int *param_1,int param_2)

{
  IStream *pIVar1;
  IStream *pstm;
  HIMAGELIST p_Var2;
  int iVar3;
  int *piVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = (undefined1 *)0x4347ef;
  pIVar1 = (IStream *)FUN_004151c4((int *)&PTR_FUN_0040e784,'\x01',param_2,0);
  puStack_14 = &LAB_00434851;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  pstm = pIVar1;
  if (pIVar1 != (IStream *)0x0) {
    pstm = pIVar1 + 5;
  }
  p_Var2 = ImageList_Read(pstm);
  FUN_00433984(param_1,p_Var2);
  iVar3 = FUN_004339b0(param_1);
  if (iVar3 == 0) {
    piVar4 = FUN_0040ad20((int *)&DAT_0040dadc,'\x01',(undefined4 *)PTR_PTR_0047c8bc);
    FUN_00403604(piVar4);
  }
  *in_FS_OFFSET = uStack_18;
  puStack_14 = (undefined1 *)0x434850;
  FUN_00402eac((int *)pIVar1);
  return;
}

