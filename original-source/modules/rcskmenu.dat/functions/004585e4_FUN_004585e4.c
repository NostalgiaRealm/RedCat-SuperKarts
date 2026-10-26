/*
 * FUN_004585e4 at 004585e4
 * undefined __register FUN_004585e4(int param_1, int param_2)
 * Address ranges: 004585e4-00458791
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004585e4(int param_1,int param_2)

{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_ECX;
  int unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 *in_FS_OFFSET;
  undefined1 *puVar7;
  char *pcVar8;
  char *pcVar9;
  undefined *puVar10;
  undefined4 uStack_30;
  undefined4 *local_2c;
  undefined1 *local_28;
  undefined *local_24;
  undefined1 *local_20;
  undefined4 *local_1c;
  
  iVar6 = 5;
  do {
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  local_1c = (undefined4 *)0x458603;
  FUN_00403f84(param_2);
  local_20 = &LAB_004587bc;
  local_24 = (undefined *)*in_FS_OFFSET;
  *in_FS_OFFSET = &local_24;
  local_2c = (undefined4 *)&LAB_00458792;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  local_28 = &stack0xfffffffc;
  local_1c = (undefined4 *)&stack0xfffffffc;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_24);
  FUN_004081c4(local_24,(int *)&local_20);
  FUN_00403e90((int *)&local_1c,3);
  piVar2 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_1c);
  piVar3 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  puVar10 = &DAT_004587f8;
  pcVar9 = "scores";
  FUN_00403e90((int *)&stack0xffffffe8,3);
  iVar6 = 0;
  do {
    pcVar8 = "-,0,0,0,0";
    puVar7 = &stack0xffffffec;
    FUN_00407f60(iVar6,(int *)&local_28);
    (**(code **)*piVar2)(piVar2,unaff_EDI,local_28,puVar7,pcVar8,pcVar9,puVar10,param_2);
    iVar4 = FUN_00403dd0(unaff_ESI);
    if (iVar4 < 1) {
      *(int *)(param_1 + 4 + iVar6 * 0x18) = iVar6;
      FUN_00403ba4((int *)(param_1 + 8 + iVar6 * 0x18),(undefined4 *)&DAT_00458834);
      *(undefined1 *)(param_1 + 0xc + iVar6 * 0x18) = 0;
      *(undefined4 *)(param_1 + 0x10 + iVar6 * 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14 + iVar6 * 0x18) = 0;
      *(undefined1 *)(param_1 + 0x18 + iVar6 * 0x18) = 0;
    }
    else {
      FUN_00454510((int)piVar3,unaff_ESI);
      iVar4 = FUN_00454750((int)piVar3);
      if (iVar4 == 5) {
        *(int *)(param_1 + 4 + iVar6 * 0x18) = iVar6;
        FUN_0045471c((int)piVar3,0,(int *)&local_2c);
        FUN_00403ba4((int *)(param_1 + 8 + iVar6 * 0x18),local_2c);
        uVar1 = FUN_004546b4((int)piVar3,1);
        *(undefined1 *)(param_1 + 0xc + iVar6 * 0x18) = uVar1;
        uVar5 = FUN_004546b4((int)piVar3,2);
        *(undefined4 *)(param_1 + 0x10 + iVar6 * 0x18) = uVar5;
        uVar5 = FUN_004546b4((int)piVar3,3);
        *(undefined4 *)(param_1 + 0x14 + iVar6 * 0x18) = uVar5;
        uVar1 = FUN_004546b4((int)piVar3,4);
        *(undefined1 *)(param_1 + 0x18 + iVar6 * 0x18) = uVar1;
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 != 5);
  *in_FS_OFFSET = pcVar9;
  FUN_00402eac(piVar2);
  return;
}

