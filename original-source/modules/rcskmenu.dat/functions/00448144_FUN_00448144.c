/*
 * FUN_00448144 at 00448144
 * undefined __register FUN_00448144(int param_1, int * param_2)
 * Address ranges: 00448144-0044831e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448144(int param_1,int *param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined1 *extraout_ECX;
  undefined1 *extraout_ECX_00;
  undefined1 *extraout_ECX_01;
  undefined1 *puVar5;
  uint extraout_ECX_02;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar6;
  undefined4 extraout_EDX_03;
  int iVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar8;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  puStack_34 = &stack0xfffffffc;
  local_10 = 0;
  puStack_38 = &LAB_0044833c;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  local_c = param_1;
  local_8 = param_2;
  FUN_0044881c(param_1,*(int **)(param_1 + 100),0);
  FUN_00447858(local_c);
  uVar8 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffb8;
  (**(code **)(*local_8 + 4))(local_8,&local_20,4);
  (**(code **)(*local_8 + 4))(local_8,&local_24,4);
  if (-1 < local_24 + -1) {
    local_20 = 0;
    puVar5 = extraout_ECX;
    uVar6 = extraout_EDX;
    iVar7 = local_24;
    do {
      puVar1 = &stack0xfffffffc;
      FUN_004480fc(&local_10,uVar6,(uint)puVar5,(int)&stack0xfffffffc);
      puVar5 = puVar1;
      uVar6 = extraout_EDX_00;
      if (local_10 != 0) {
        FUN_00403088(*(int **)(local_c + 0x14),local_10,&local_14);
        puVar5 = extraout_ECX_00;
        uVar6 = extraout_EDX_01;
        if (local_14 != (int *)0x0) {
          FUN_0043f564(local_14,0,extraout_ECX_00);
          uVar8 = 0;
          FUN_00440188(local_14,*(int **)(local_c + 0x14),0,0);
          puVar5 = extraout_ECX_01;
          uVar6 = extraout_EDX_02;
        }
      }
      local_20 = local_20 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  (**(code **)(*local_8 + 4))(local_8,local_c + 0x68,4);
  local_1c = 0;
  piVar4 = (int *)0x0;
LAB_00448221:
  do {
    (**(code **)(*local_8 + 4))(local_8,&local_18,4);
    if (local_18 == DAT_0047ba0c) {
      *in_FS_OFFSET = uVar8;
      FUN_0044785c(local_c);
      return;
    }
    piVar2 = (int *)FUN_004471e4((int *)&LAB_0043c5c0,'\x01',local_c);
    (**(code **)(*local_8 + 4))(local_8,piVar2 + 4,1);
    (**(code **)(*local_8 + 4))(local_8,piVar2 + 8,4);
    FUN_004480fc(&local_10,extraout_EDX_03,extraout_ECX_02,(int)&stack0xfffffffc);
    if (local_10 != 0) {
      uVar3 = FUN_00447494((int)piVar2,local_10);
      if ((char)uVar3 == '\0') {
        FUN_00402eac(piVar2);
        goto LAB_00448221;
      }
    }
    if (local_18 == 0) {
      *(int **)(local_c + 100) = piVar2;
    }
    else if (local_18 == local_1c) {
      piVar4[3] = (int)piVar2;
      piVar2[6] = (int)piVar4;
      piVar2[5] = piVar4[5];
    }
    else if (local_1c < local_18) {
      piVar4[2] = (int)piVar2;
      piVar2[5] = (int)piVar4;
    }
    else if (local_18 < local_1c) {
      local_1c = local_1c - local_18;
      if (0 < local_1c) {
        local_20 = 1;
        do {
          piVar4 = (int *)piVar4[5];
          local_20 = local_20 + 1;
          local_1c = local_1c + -1;
        } while (local_1c != 0);
      }
      piVar4[3] = (int)piVar2;
      piVar2[6] = (int)piVar4;
      piVar2[5] = piVar4[5];
    }
    local_1c = local_18;
    piVar4 = piVar2;
  } while( true );
}

