/*
 * FUN_00413c68 at 00413c68
 * undefined __register FUN_00413c68(int * param_1, int * param_2)
 * Address ranges: 00413c68-00413e82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413c68(int *param_1,int *param_2)

{
  LPVOID pvVar1;
  int *piVar2;
  int iVar3;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  undefined4 extraout_ECX_02;
  int unaff_EDI;
  int *in_FS_OFFSET;
  int iStack_4c;
  undefined1 *puStack_48;
  undefined1 *puStack_44;
  int iStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  int iStack_34;
  undefined4 *local_30;
  undefined1 *local_2c;
  int local_28;
  undefined1 *local_24;
  undefined1 *local_20;
  int iVar4;
  int *local_10;
  
  local_20 = &stack0xfffffffc;
  iVar3 = 5;
  do {
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_24 = &LAB_00413efa;
  local_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_28;
  local_2c = (undefined1 *)0x413c97;
  FUN_00413fc8((int)param_1,param_2,0);
  local_2c = (undefined1 *)0x413ca6;
  FUN_0040bf7c(DAT_0047d618);
  local_30 = (undefined4 *)&LAB_00413ed8;
  iStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_34;
  puStack_3c = &LAB_00413e99;
  iStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_40;
  puStack_44 = (undefined1 *)0x413cd0;
  puStack_38 = &stack0xfffffffc;
  local_2c = &stack0xfffffffc;
  (**(code **)(*param_1 + 0x24))(param_1,&stack0xffffffeb,&stack0xffffffec);
  if (param_2 == (int *)0x0) {
    puStack_44 = (undefined1 *)0x413ce1;
    FUN_00413fec((int)param_1,(int *)&stack0xffffffe4,extraout_ECX);
    puStack_44 = (undefined1 *)0x413ce9;
    iVar3 = FUN_0040ed48(unaff_EDI);
    puStack_44 = (undefined1 *)0x413cf0;
    local_10 = (int *)(**(code **)(iVar3 + 0x2c))(iVar3,1,0);
    puStack_44 = (undefined1 *)0x413cfe;
    FUN_00413fec((int)param_1,(int *)&local_20,extraout_ECX_00);
    puStack_44 = (undefined1 *)0x413d09;
    (**(code **)(*local_10 + 0x18))(local_10,local_20);
  }
  else {
    puStack_44 = (undefined1 *)0x413d1c;
    FUN_00413fec((int)param_1,(int *)&local_24,extraout_ECX);
    local_10 = param_2;
    if ((*(byte *)(param_2 + 8) & 0x10) == 0) {
      *(ushort *)(param_2 + 8) = *(ushort *)(param_2 + 8) | 1;
      *(ushort *)(param_2 + 8) = *(ushort *)(param_2 + 8) | 2;
      puStack_44 = (undefined1 *)0x413d4d;
      FUN_00413fec((int)param_1,(int *)&local_30,extraout_ECX_01);
      puStack_44 = (undefined1 *)0x413d58;
      FUN_00413bf8(local_30,(int *)&local_2c);
      puStack_44 = (undefined1 *)0x413d63;
      (**(code **)(*param_2 + 0x18))(param_2,local_2c);
    }
    else {
      puStack_44 = (undefined1 *)0x413d30;
      FUN_00413fec((int)param_1,&local_28,extraout_ECX_01);
    }
  }
  param_1[6] = (int)local_10;
  param_1[7] = (int)local_10;
  puStack_44 = (undefined1 *)0x413d7a;
  pvVar1 = FUN_00406144();
  if (*(int *)((int)pvVar1 + 8) == 0) {
    puStack_44 = (undefined1 *)0x413da2;
    iVar3 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_02);
    param_1[0xd] = iVar3;
  }
  else {
    puStack_44 = (undefined1 *)0x413d88;
    pvVar1 = FUN_00406144();
    param_1[0xd] = *(int *)((int)pvVar1 + 8);
  }
  puStack_48 = &LAB_00413e83;
  iStack_4c = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_4c;
  puStack_44 = &stack0xfffffffc;
  iVar3 = FUN_0040f70c(param_1[0xd],param_1[6]);
  if (iVar3 < 0) {
    FUN_0040f504((int *)param_1[0xd],param_1[6]);
  }
  param_1[10] = param_1[6];
  *(ushort *)(param_1[6] + 0x20) = *(ushort *)(param_1[6] + 0x20) | 1;
  *(ushort *)(param_1[6] + 0x20) = *(ushort *)(param_1[6] + 0x20) | 2;
  (**(code **)(*(int *)param_1[6] + 0x14))((int *)param_1[6],param_1);
  *(ushort *)(param_1[6] + 0x20) = *(ushort *)(param_1[6] + 0x20) & 0xfffd;
  pvVar1 = FUN_00406144();
  if ((*(int *)((int)pvVar1 + 8) == 0) && (iVar3 = *(int *)(param_1[0xd] + 8), -1 < iVar3 + -1)) {
    iVar4 = 0;
    do {
      piVar2 = (int *)FUN_0040f6b0((undefined4 *)param_1[0xd],iVar4);
      (**(code **)(*piVar2 + 0xc))();
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *in_FS_OFFSET = iStack_4c;
  puStack_44 = &LAB_00413e8a;
  puStack_48 = (undefined1 *)0x413e66;
  pvVar1 = FUN_00406144();
  if (*(int *)((int)pvVar1 + 8) == 0) {
    puStack_48 = (undefined1 *)0x413e7a;
    FUN_00402eac((int *)param_1[0xd]);
  }
  param_1[0xd] = 0;
  return;
}

