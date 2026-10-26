/*
 * FUN_004488b4 at 004488b4
 * undefined __register FUN_004488b4(int param_1, int * param_2)
 * Address ranges: 004488b4-00448b09
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004488b4(int param_1,int *param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar4;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puStack_24 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  puStack_28 = &LAB_00448b0a;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puVar1 = &stack0xfffffffc;
  if (param_2 == (int *)0x0) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c744,(int *)&local_8);
    FUN_00405438((undefined4 *)PTR_PTR_0047c640,(int *)&local_c);
    FUN_00403dd8((int *)&local_8,local_c);
    piVar2 = FUN_0040ac64((int *)&DAT_004070f4,'\x01',local_8);
    FUN_00403604(piVar2);
    puVar1 = puStack_24;
  }
  puStack_24 = puVar1;
  if (param_2[1] == 0) {
    FUN_00405438((undefined4 *)PTR_PTR_0047c744,(int *)&local_10);
    FUN_00405438((undefined4 *)PTR_PTR_0047c8cc,(int *)&local_14);
    FUN_00403dd8((int *)&local_10,local_14);
    piVar2 = FUN_0040ac64((int *)&DAT_004070f4,'\x01',local_10);
    FUN_00403604(piVar2);
  }
  iVar3 = FUN_00447208(param_2[5]);
  if (iVar3 == 1) {
    iVar3 = *(int *)(param_1 + 100);
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined1 *)(iVar3 + 0x10) = 0;
  }
  else if (iVar3 == 2) {
    piVar2 = (int *)param_2[6];
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)param_2[3];
    }
    if (piVar2[1] == 0) {
      if (param_2[5] == *(int *)(param_1 + 100)) {
        piVar2[8] = *(int *)(param_1 + 0x68);
        *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(*(int *)(param_1 + 100) + 0x20);
        FUN_00402eac(*(int **)(param_1 + 100));
        *(int **)(param_1 + 100) = piVar2;
        piVar2[3] = 0;
        piVar2[6] = 0;
        piVar2[5] = 0;
        FUN_0044903c(param_1);
      }
      else {
        iVar3 = *(int *)(param_2[5] + 0x18);
        *(int *)(piVar2[2] + 0x18) = iVar3;
        if (iVar3 == 0) {
          *(int *)(*(int *)(param_2[5] + 0x14) + 8) = piVar2[2];
        }
        else {
          *(int *)(iVar3 + 0xc) = piVar2[2];
        }
        iVar3 = piVar2[2];
        *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_2[5] + 0x14);
        do {
          iVar3 = *(int *)(iVar3 + 0xc);
          *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_2[5] + 0x14);
        } while (*(int *)(iVar3 + 0xc) != 0);
        *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_2[5] + 0xc);
        if (*(int *)(iVar3 + 0xc) != 0) {
          *(int *)(*(int *)(iVar3 + 0xc) + 0x18) = iVar3;
        }
        FUN_00447930(param_1,*(int *)(iVar3 + 0x14),extraout_ECX);
        FUN_00402eac((int *)param_2[5]);
        FUN_00402eac(piVar2);
      }
    }
    else {
      iVar3 = param_2[5];
      if (*(int *)(param_1 + 100) == iVar3) {
        *(int **)(*(int *)(param_1 + 100) + 8) = piVar2;
        piVar2[6] = 0;
        piVar2[3] = 0;
        iVar3 = FUN_00447264(*(int *)(param_1 + 100));
        piVar2[8] = iVar3;
        FUN_00447540((int)piVar2);
        uVar4 = extraout_ECX_00;
      }
      else {
        *(undefined1 *)(iVar3 + 0x10) = 0;
        *(int *)(iVar3 + 4) = piVar2[1];
        *(undefined4 *)(iVar3 + 8) = 0;
        FUN_00402eac(piVar2);
        uVar4 = extraout_ECX_01;
      }
      FUN_00447930(param_1,param_2[5],uVar4);
    }
  }
  else {
    iVar3 = param_2[6];
    if (iVar3 == 0) {
      *(int *)(param_2[5] + 8) = param_2[3];
      iVar3 = param_2[3];
      *(undefined4 *)(iVar3 + 0x18) = 0;
      FUN_00447540(iVar3);
      uVar4 = extraout_ECX_02;
    }
    else {
      *(int *)(iVar3 + 0xc) = param_2[3];
      if (param_2[3] != 0) {
        *(int *)(param_2[3] + 0x18) = iVar3;
      }
      iVar3 = param_2[6];
      *(int *)(iVar3 + 0x20) = param_2[8];
      FUN_00447540(iVar3);
      uVar4 = extraout_ECX_03;
    }
    FUN_00447930(param_1,param_2[5],uVar4);
  }
  FUN_00402eac(param_2);
  *in_FS_OFFSET = uStack_2c;
  puStack_24 = &LAB_00448b11;
  puStack_28 = (undefined1 *)0x448b09;
  FUN_00403b74((int *)&local_14,4);
  return;
}

