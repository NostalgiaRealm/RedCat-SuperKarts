/*
 * FUN_0041350c at 0041350c
 * undefined __register FUN_0041350c(int * param_1, int * param_2)
 * Address ranges: 0041350c-0041365d;0041367b-00413684;004136ba-004136cf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041350c(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_48;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined4 local_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 local_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  int *local_18;
  int *local_14;
  int local_c;
  int *local_8;
  
  puStack_28 = &stack0xfffffffc;
  puStack_34 = &stack0xfffffffc;
  local_c = 0;
  puStack_2c = &LAB_004136d0;
  local_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &local_30;
  puStack_38 = &LAB_00413685;
  local_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &local_3c;
  puStack_40 = (undefined1 *)0x413547;
  local_8 = param_2;
  FUN_00413fec((int)param_1,&local_c,0);
  puStack_44 = &LAB_0041365e;
  uStack_48 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_48;
  iVar5 = 1;
  puStack_40 = &stack0xfffffffc;
  iVar1 = FUN_00403dd0(local_c);
  local_14 = local_8;
  *(undefined1 *)(param_1 + 0x1d) = 1;
  iVar2 = iVar5;
  while( true ) {
    for (; (iVar5 <= iVar1 && (*(char *)(local_c + -1 + iVar5) != '.')); iVar5 = iVar5 + 1) {
    }
    FUN_00403fd8(local_c,iVar2,iVar5 - iVar2,param_1 + 0x1c);
    if (iVar1 < iVar5) break;
    iVar2 = FUN_004030cc(*local_14);
    puVar3 = (undefined4 *)FUN_0040d2c0(iVar2,(undefined1 *)param_1[0x1c]);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_00412920((int)param_1,extraout_EDX,extraout_ECX);
    }
    local_18 = (int *)0x0;
    if (**(char **)*puVar3 == '\a') {
      local_18 = (int *)FUN_0040d380(local_14,puVar3);
    }
    uVar4 = FUN_00403024(local_18,(int)&PTR_FUN_0040df7c);
    if ((char)uVar4 == '\0') {
      FUN_004134f0(uVar4,extraout_EDX_00,extraout_ECX_00,(int)&stack0xfffffffc);
    }
    local_14 = local_18;
    iVar5 = iVar5 + 1;
    iVar2 = iVar5;
  }
  iVar2 = FUN_004030cc(*local_14);
  puVar3 = (undefined4 *)FUN_0040d2c0(iVar2,(undefined1 *)param_1[0x1c]);
  if (puVar3 == (undefined4 *)0x0) {
    *(undefined1 *)(param_1 + 0x1d) = 0;
    (**(code **)(*local_14 + 4))(local_14,param_1);
    *(undefined1 *)(param_1 + 0x1d) = 1;
    if (param_1[0x1c] != 0) {
      FUN_00412920((int)param_1,extraout_EDX_01,extraout_ECX_01);
    }
  }
  else {
    FUN_00413960(param_1,local_14,puVar3);
  }
  *in_FS_OFFSET = uStack_48;
  *in_FS_OFFSET = local_3c;
  *in_FS_OFFSET = local_30;
  puStack_28 = &LAB_004136d7;
  puStack_2c = (undefined1 *)0x4136cf;
  FUN_00403b50(&local_c);
  return;
}

