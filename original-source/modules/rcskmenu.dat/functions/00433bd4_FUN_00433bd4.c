/*
 * FUN_00433bd4 at 00433bd4
 * undefined __register FUN_00433bd4(int * param_1, int param_2)
 * Address ranges: 00433bd4-00433c52
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00433bd4(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  HIMAGELIST himl;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_18 = &LAB_00433c53;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  iVar2 = FUN_00433bb0(param_1);
  if (iVar2 <= param_2) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c6ec,(int *)&local_8);
    piVar3 = FUN_0040ac64((int *)&DAT_0040de0c,'\x01',local_8);
    FUN_00403604(piVar3);
  }
  bVar1 = FUN_00433874((int)param_1);
  uVar4 = extraout_ECX;
  uVar5 = extraout_EDX;
  if (bVar1) {
    himl = (HIMAGELIST)FUN_004339b0(param_1);
    ImageList_Remove(himl,param_2);
    uVar4 = extraout_ECX_00;
    uVar5 = extraout_EDX_00;
  }
  FUN_00403088(param_1,uVar5,uVar4);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00433c5a;
  puStack_18 = (undefined1 *)0x433c52;
  FUN_00403b50((int *)&local_8);
  return;
}

