/*
 * FUN_00442074 at 00442074
 * undefined __register FUN_00442074(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00442074-00442139;00442141-0044215d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442074(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  puVar7 = &stack0xfffffffc;
  puVar8 = &stack0xfffffffc;
  if ((((char)param_1[0x51] != '\0') && ((char)param_1[0x5f] != '\0')) && (param_1[0x52] != 0)) {
    puStack_1c = (undefined1 *)0x4420b8;
    (**(code **)(*(int *)param_1[0x52] + 0x2c))((int *)param_1[0x52],0);
  }
  puStack_20 = (undefined1 *)0x4420be;
  puStack_1c = &stack0xfffffffc;
  uVar2 = FUN_00442020();
  puVar1 = puStack_1c;
  if ((char)uVar2 != '\0') {
    puStack_1c = (undefined1 *)0x4420d1;
    (**(code **)(*param_1 + 0x84))(param_1,param_3);
    puStack_1c = (undefined1 *)0x4420dd;
    piVar3 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX);
    puStack_20 = &LAB_0044213a;
    uStack_24 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_24;
    puStack_1c = &stack0xfffffffc;
    FUN_00441ecc(1,extraout_EDX_00,extraout_ECX_00,(int)&stack0xfffffffc);
    FUN_00441ecc(2,extraout_EDX_01,puVar4,(int)&stack0xfffffffc);
    FUN_00441ecc(3,extraout_EDX_02,puVar5,(int)&stack0xfffffffc);
    FUN_00441ecc(4,extraout_EDX_03,puVar6,(int)&stack0xfffffffc);
    FUN_00441ecc(5,extraout_EDX_04,puVar7,(int)&stack0xfffffffc);
    FUN_00441ecc(0,extraout_EDX_05,puVar8,(int)&stack0xfffffffc);
    *in_FS_OFFSET = uStack_24;
    puStack_1c = (undefined1 *)0x442141;
    puStack_20 = (undefined1 *)0x442139;
    FUN_00402eac(piVar3);
    return;
  }
  if ((char)param_1[0x5a] != '\0') {
    puStack_1c = (undefined1 *)0x442159;
    FUN_00403088(param_1,extraout_EDX,puVar1);
  }
  return;
}

