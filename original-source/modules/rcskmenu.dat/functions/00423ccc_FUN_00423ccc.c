/*
 * FUN_00423ccc at 00423ccc
 * undefined __register FUN_00423ccc(int * param_1, char * param_2, int param_3)
 * Address ranges: 00423ccc-00423d55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423ccc(int *param_1,char *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  int local_c;
  
  puStack_20 = (undefined1 *)0x423ce6;
  iVar1 = (**(code **)(*param_1 + 0xbc))();
  puStack_20 = (undefined1 *)0x423cf2;
  local_c = (**(code **)(*param_1 + 0xb8))();
  puStack_20 = (undefined1 *)0x423cfc;
  iVar2 = FUN_0043f5c0((int)param_1);
  puStack_20 = (undefined1 *)0x423d02;
  piVar3 = FUN_00408528(iVar2 + 1);
  puStack_24 = &LAB_00423d56;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  iVar2 = FUN_0040853c((int)piVar3);
  FUN_0043f5d0((int)param_1,piVar3,iVar2);
  if (param_3 <= local_c) {
    local_c = param_3 + -1;
  }
  FUN_004083d0(param_2,(char *)((int)piVar3 + iVar1),local_c);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_00423d5d;
  puStack_24 = (undefined1 *)0x423d55;
  FUN_00408574((int)piVar3);
  return;
}

