/*
 * FUN_0045c7cc at 0045c7cc
 * undefined __register FUN_0045c7cc(undefined4 * param_1, int * param_2)
 * Address ranges: 0045c7cc-0045c8ef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045c7cc(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  LPCSTR lpRootPathName;
  UINT UVar2;
  undefined4 uVar3;
  undefined4 unaff_EBX;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined *local_24;
  byte local_20 [5];
  undefined1 local_1b [3];
  undefined4 *local_18;
  undefined *local_14;
  int local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = (undefined4 *)0x0;
  local_10 = 0;
  local_14 = (undefined *)0x0;
  local_18 = (undefined4 *)0x0;
  stack0xffffffe4 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_24 = (undefined *)0x0;
  puStack_30 = (undefined1 *)0x45c7e8;
  local_8 = param_1;
  FUN_00403f84((int)param_1);
  puStack_34 = &LAB_0045c8f0;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_30 = &stack0xfffffffc;
  FUN_00403b50(param_2);
  FUN_00403b50(&local_10);
  iVar4 = CONCAT31((int3)((uint)unaff_EBX >> 8),99);
  do {
    FUN_00403cf8((int *)&local_18,iVar4);
    FUN_00403e1c((int *)&local_14,local_18,(undefined4 *)&DAT_0045c908);
    stack0xffffffe4 = CONCAT31(CONCAT21(local_1b._1_2_,(char)iVar4),1);
    FUN_00402a14(local_20,local_20 + 4);
    FUN_004029e4(local_20,&DAT_0045c90c,2);
    FUN_00403d74((int *)&local_c,local_20);
    lpRootPathName = FUN_00403f94((undefined *)local_c);
    UVar2 = GetDriveTypeA(lpRootPathName);
    if (UVar2 == 5) {
      bVar1 = FUN_00408328(local_14);
      if (bVar1) {
        stack0xffffffe4 = CONCAT31(CONCAT21(local_1b._1_2_,(char)iVar4),1);
        FUN_00402a14(local_20,local_20 + 4);
        FUN_004029e4(local_20,&DAT_0045c90c,2);
        FUN_00403d74((int *)&local_24,local_20);
        FUN_00403dd8((int *)&local_24,local_8);
        uVar3 = FUN_0040811c(local_24);
        if ((char)uVar3 != '\0') {
          FUN_00403ba4(param_2,local_c);
          break;
        }
      }
    }
    iVar4 = iVar4 + 1;
  } while ((char)iVar4 != '{');
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_0045c8f7;
  puStack_34 = (undefined1 *)0x45c8e2;
  FUN_00403b50((int *)&local_24);
  puStack_34 = (undefined1 *)0x45c8ef;
  FUN_00403b74((int *)&local_18,5);
  return;
}

