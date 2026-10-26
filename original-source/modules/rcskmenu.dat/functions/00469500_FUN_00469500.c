/*
 * FUN_00469500 at 00469500
 * undefined __register FUN_00469500(DWORD param_1, int param_2, int param_3, char param_4)
 * Address ranges: 00469500-004695a0;004695a3-004695c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00469500(DWORD param_1,int param_2,int param_3,char param_4)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  DWORD DVar5;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  puStack_20 = &stack0xfffffffc;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  puStack_24 = &LAB_004695c5;
  puStack_28 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_28;
  local_8 = param_3;
  if (param_1 == 0x80020009) {
    DVar5 = *(DWORD *)(param_2 + 0x1c);
    puStack_20 = &stack0xfffffffc;
    FUN_00403d98((int *)&local_c,*(LPCWSTR *)(param_2 + 4));
    puVar4 = local_c;
    FUN_00403d98((int *)&local_10,*(LPCWSTR *)(param_2 + 0xc));
    iVar2 = *(int *)(param_2 + 0x10);
    puVar3 = local_10;
    FUN_00403d98((int *)&local_14,*(LPCWSTR *)(param_2 + 8));
    uVar1 = FUN_00468d88((int *)&DAT_00468c0c,'\x01',local_14,iVar2,puVar3,puVar4,DVar5);
    if (param_4 != '\0') {
      FUN_004044e0(param_2,&DAT_0040ce14);
    }
  }
  else {
    puVar4 = (undefined4 *)0x0;
    uVar1 = FUN_00468cb8((int *)&DAT_00468bb0,'\x01',0,0,param_1);
  }
  if (local_8 != 0) {
    FUN_00403604(uVar1);
    return;
  }
  FUN_00403604(uVar1);
  *in_FS_OFFSET = puVar4;
  puStack_28 = &LAB_004695cc;
  FUN_00403b74((int *)&local_14,3);
  return;
}

