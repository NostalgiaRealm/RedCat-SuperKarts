/*
 * FUN_00423d68 at 00423d68
 * undefined __register FUN_00423d68(int * param_1, int * param_2)
 * Address ranges: 00423d68-00423df5;00423dfd-00423e03
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423d68(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = (undefined1 *)0x423d7f;
  iVar1 = (**(code **)(*param_1 + 0xbc))();
  puStack_1c = (undefined1 *)0x423d8c;
  uVar2 = (**(code **)(*param_1 + 0xb8))();
  puStack_1c = (undefined1 *)0x423d99;
  FUN_00403c38(param_2,(undefined4 *)0x0,uVar2);
  if (uVar2 != 0) {
    puStack_1c = (undefined1 *)0x423da4;
    iVar3 = FUN_0043f5c0((int)param_1);
    puStack_1c = (undefined1 *)0x423daa;
    piVar4 = FUN_00408528(iVar3 + 1);
    puStack_20 = &LAB_00423df6;
    uStack_24 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_24;
    puStack_1c = &stack0xfffffffc;
    iVar3 = FUN_0040853c((int)piVar4);
    FUN_0043f5d0((int)param_1,piVar4,iVar3);
    FUN_0040282c((undefined4 *)((int)piVar4 + iVar1),(undefined4 *)*param_2,uVar2);
    *in_FS_OFFSET = uStack_24;
    puStack_1c = (undefined1 *)0x423dfd;
    puStack_20 = (undefined1 *)0x423df5;
    FUN_00408574((int)piVar4);
    return;
  }
  return;
}

