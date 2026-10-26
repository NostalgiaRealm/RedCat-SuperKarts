/*
 * FUN_00458838 at 00458838
 * undefined __register FUN_00458838(int param_1, int param_2)
 * Address ranges: 00458838-00458978
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00458838(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 *unaff_EDI;
  int *in_FS_OFFSET;
  undefined4 uVar3;
  char *pcVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  undefined1 *puVar9;
  undefined1 *local_34;
  int local_30;
  undefined1 *local_2c;
  undefined1 *local_28;
  int local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  
  iVar2 = 6;
  do {
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_1c = (undefined1 *)0x458857;
  FUN_00403f84(param_2);
  local_20 = &LAB_004589a3;
  local_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_24;
  local_2c = &LAB_00458979;
  local_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_30;
  local_34 = (undefined1 *)0x458882;
  local_28 = &stack0xfffffffc;
  local_1c = &stack0xfffffffc;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_20);
  local_34 = (undefined1 *)0x45888d;
  FUN_004081c4(local_20,(int *)&local_1c);
  local_34 = local_1c;
  FUN_00403e90((int *)&stack0xffffffe8,3);
  piVar1 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_EDI);
  iVar2 = 0;
  do {
    FUN_00407f60((uint)*(byte *)(param_1 + 0xc + iVar2 * 0x18),&local_24);
    FUN_00407f60(*(undefined4 *)(param_1 + 0x10 + iVar2 * 0x18),(int *)&local_28);
    FUN_00407f60(*(undefined4 *)(param_1 + 0x14 + iVar2 * 0x18),(int *)&local_2c);
    puVar8 = &DAT_004589e0;
    puVar9 = local_2c;
    FUN_00407f60((uint)*(byte *)(param_1 + 0x18 + iVar2 * 0x18),&local_30);
    iVar7 = local_30;
    FUN_00403e90((int *)&stack0xfffffff0,9);
    puVar5 = &DAT_004589ec;
    pcVar4 = "scores";
    iVar6 = param_2;
    FUN_00403e90((int *)&stack0xffffffec,3);
    uVar3 = unaff_EBX;
    FUN_00407f60(iVar2,(int *)&local_34);
    (**(code **)(*piVar1 + 4))
              (piVar1,unaff_ESI,local_34,uVar3,pcVar4,puVar5,iVar6,iVar7,puVar8,puVar9);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  *in_FS_OFFSET = (int)"scores.dat";
  local_34 = &LAB_00458980;
  FUN_00402eac(piVar1);
  return;
}

