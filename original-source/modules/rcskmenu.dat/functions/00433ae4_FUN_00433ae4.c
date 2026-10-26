/*
 * FUN_00433ae4 at 00433ae4
 * undefined __register FUN_00433ae4(int * param_1, int * param_2, int * param_3)
 * Address ranges: 00433ae4-00433b75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00433ae4(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  HBITMAP hbmMask;
  HBITMAP hbmImage;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  
  puStack_20 = (undefined1 *)0x433aff;
  piVar1 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',param_3);
  puStack_24 = &LAB_00433b93;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_2c = (undefined1 *)0x433b1c;
  puStack_20 = &stack0xfffffffc;
  piVar2 = FUN_0041c7f0((int *)&PTR_FUN_00416860,'\x01',extraout_ECX);
  puStack_30 = &LAB_00433b76;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_2c = &stack0xfffffffc;
  FUN_0043387c(param_1);
  hbmMask = (HBITMAP)FUN_004339c0((int)param_1,param_3,piVar2);
  hbmImage = (HBITMAP)FUN_004339c0((int)param_1,param_2,piVar1);
  ImageList_Add((HIMAGELIST)param_1[0xc],hbmImage,hbmMask);
  *in_FS_OFFSET = uStack_34;
  puStack_2c = &LAB_00433b7d;
  puStack_30 = (undefined1 *)0x433b75;
  FUN_00402eac(piVar2);
  return;
}

