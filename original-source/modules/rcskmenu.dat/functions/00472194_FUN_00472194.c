/*
 * FUN_00472194 at 00472194
 * undefined __register FUN_00472194(int param_1)
 * Address ranges: 00472194-00472393;0047239e-004723bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472194(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_ESI;
  undefined4 *unaff_EDI;
  int *in_FS_OFFSET;
  uint **ppuVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined *puVar9;
  int iStack_3c;
  undefined1 *puStack_38;
  undefined1 *local_34;
  uint *local_30;
  undefined1 *local_2c;
  uint *local_28;
  int local_24;
  uint *local_20;
  undefined4 *local_1c;
  
  local_1c = (undefined4 *)&stack0xfffffffc;
  local_28 = (uint *)&stack0xfffffffc;
  local_34 = &stack0xfffffffc;
  iVar5 = 6;
  do {
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_20 = (uint *)&LAB_004723de;
  local_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_24;
  local_2c = &LAB_004723bc;
  local_30 = (uint *)*in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_30;
  puStack_38 = &LAB_00472394;
  iStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_3c;
  FUN_00403e1c((int *)&stack0xffffffe8,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)"race.ini");
  piVar2 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_EDI);
  uVar4 = *(undefined4 *)PTR_DAT_0047c694;
  puVar9 = &DAT_00472408;
  pcVar8 = "shellimg.dat";
  FUN_00403e90((int *)&local_1c,3);
  piVar3 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_1c);
  uVar4 = (**(code **)(*piVar2 + 8))(piVar2,"PLAYER","position",0,pcVar8,puVar9,uVar4);
  *(undefined4 *)(param_1 + 0x330) = uVar4;
  uVar4 = (**(code **)(*piVar2 + 8))(piVar2,"PLAYER","tracktime",0);
  *(undefined4 *)(param_1 + 0x334) = uVar4;
  uVar4 = (**(code **)(*piVar2 + 8))(piVar2,"PLAYER","FASTEST_LAP",0);
  *(undefined4 *)(param_1 + 0x338) = uVar4;
  FUN_0045c910(*(int *)(param_1 + 0x334),(int *)&stack0xfffffff0);
  FUN_0045c910(*(int *)(param_1 + 0x338),(int *)&stack0xffffffec);
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x01') {
    FUN_0043f67c(*(int *)(param_1 + 0x308),
                 *(uint **)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0xc));
  }
  else {
    FUN_0043f67c(*(int *)(param_1 + 0x308),
                 *(uint **)(PTR_PTR_0047c5e0 +
                           (uint)*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22) * 4));
  }
  FUN_0045c4c8(0x22,&local_24);
  FUN_00403e90((int *)&local_20,3);
  FUN_0043f67c(*(int *)(param_1 + 0x30c),local_20);
  FUN_0045c4c8(0x23,(int *)&local_2c);
  puVar9 = &DAT_0047247c;
  puVar7 = local_2c;
  FUN_00403e90((int *)&local_28,3);
  FUN_0043f67c(*(int *)(param_1 + 0x310),local_28);
  uVar4 = 0;
  ppuVar6 = &local_30;
  FUN_00407f60(*(undefined4 *)(param_1 + 0x330),(int *)&local_34);
  (**(code **)*piVar3)(piVar3,"REWARDPICS",local_34,ppuVar6,uVar4,unaff_ESI,puVar9,puVar7);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x304) + 300),local_30);
  FUN_0043fb28(*(int **)(param_1 + 0x304));
  *in_FS_OFFSET = (int)ppuVar6;
  *in_FS_OFFSET = (int)puVar9;
  FUN_00402eac(piVar2);
  FUN_00402eac(piVar3);
  return;
}

