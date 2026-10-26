/*
 * FUN_00412dcc at 00412dcc
 * undefined __register FUN_00412dcc(int * param_1, int * param_2)
 * Address ranges: 00412dcc-00412f2c;00412f4f-00412f6e;00412f76-00412f90
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412dcc(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint extraout_ECX;
  uint extraout_ECX_00;
  undefined1 *extraout_ECX_01;
  undefined1 *puVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_58;
  undefined1 *puStack_54;
  undefined4 uStack_4c;
  undefined1 *puStack_48;
  undefined1 *puStack_44;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined4 local_20;
  int local_1c [2];
  int *local_14;
  int *local_10;
  int *local_c;
  byte local_5;
  
  puStack_38 = &stack0xfffffffc;
  local_1c[1] = 0;
  local_1c[0] = 0;
  puStack_3c = &LAB_00412f91;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  puStack_44 = (undefined1 *)0x412dff;
  local_10 = param_1;
  local_c = param_2;
  (**(code **)(*param_1 + 0x24))(param_1,&local_5,&local_20);
  puStack_44 = (undefined1 *)0x412e0a;
  FUN_00413fec((int)local_10,local_1c + 1,extraout_ECX);
  puStack_44 = (undefined1 *)0x412e15;
  FUN_00413fec((int)local_10,local_1c,extraout_ECX_00);
  iVar1 = local_10[0xb];
  iVar2 = local_10[7];
  puStack_48 = &LAB_00412f6f;
  uStack_4c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_4c;
  local_14 = local_c;
  puVar4 = extraout_ECX_01;
  uVar5 = extraout_EDX;
  puStack_44 = &stack0xfffffffc;
  if (local_c == (int *)0x0) {
    if ((local_5 & 1) == 0) {
      puStack_54 = (undefined1 *)0x412e56;
      puVar4 = &stack0xfffffffc;
      puStack_44 = &stack0xfffffffc;
      FUN_00412b78(0,extraout_EDX,(int)extraout_ECX_01,(int)&stack0xfffffffc);
      uVar5 = extraout_EDX_01;
    }
    else {
      puStack_54 = (undefined1 *)0x412e4d;
      puVar4 = &stack0xfffffffc;
      puStack_44 = &stack0xfffffffc;
      FUN_00412d28(0,extraout_EDX,(int)extraout_ECX_01,(int)&stack0xfffffffc);
      uVar5 = extraout_EDX_00;
    }
  }
  if (local_14 != (int *)0x0) {
    puStack_54 = &LAB_00412f2d;
    uStack_58 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_58;
    *(ushort *)(local_14 + 8) = *(ushort *)(local_14 + 8) | 1;
    if ((local_5 & 1) == 0) {
      FUN_00412c88(local_14,uVar5,puVar4,(int)&stack0xfffffffc);
    }
    if (local_14 == (int *)0x0) {
      *in_FS_OFFSET = uStack_58;
      FUN_004036a4();
      *in_FS_OFFSET = uStack_40;
      puStack_38 = &LAB_00412f98;
      puStack_3c = (undefined1 *)0x412f90;
      FUN_00403b74(local_1c,2);
      return;
    }
    if ((*(byte *)((int)local_14 + 0x21) & 2) != 0) {
      local_10[7] = (int)local_14;
    }
    *(ushort *)(local_14 + 8) = *(ushort *)(local_14 + 8) | 2;
    (**(code **)(*local_14 + 0x14))(local_14,local_10);
    *(ushort *)(local_14 + 8) = *(ushort *)(local_14 + 8) & 0xfffd;
    if ((local_5 & 2) != 0) {
      FUN_00403088((int *)local_10[0xb],local_14,local_20);
    }
    if (((local_5 & 1) == 0) && ((*(byte *)((int)local_14 + 0x21) & 2) == 0)) {
      FUN_0040f504((int *)local_10[0xd],(int)local_14);
    }
    else {
      iVar3 = FUN_0040f70c(local_10[0xd],(int)local_14);
      if (iVar3 < 0) {
        FUN_0040f504((int *)local_10[0xd],(int)local_14);
      }
    }
    *in_FS_OFFSET = uStack_58;
  }
  *in_FS_OFFSET = uStack_4c;
  local_10[0xb] = iVar1;
  local_10[7] = iVar2;
  return;
}

