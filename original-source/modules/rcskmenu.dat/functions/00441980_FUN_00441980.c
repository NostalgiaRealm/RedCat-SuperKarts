/*
 * FUN_00441980 at 00441980
 * undefined __register FUN_00441980(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00441980-00441a43;00441a4b-00441a50
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441980(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  if (*(int *)(param_1 + 0x180) != 0) {
    puStack_1c = (undefined1 *)0x4419a7;
    piVar2 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
    puStack_20 = &LAB_00441a44;
    uStack_24 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_24;
    iVar5 = *(int *)(*(int *)(param_1 + 0x180) + 8);
    puStack_1c = &stack0xfffffffc;
    FUN_0040f8a4(piVar2,iVar5);
    if (-1 < iVar5 + -1) {
      iVar6 = 0;
      iVar4 = iVar5;
      do {
        iVar3 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x180),iVar6);
        iVar1 = *(int *)(iVar3 + 0x170);
        if ((-1 < iVar1) && (iVar1 < iVar5)) {
          FUN_0040f7fc(piVar2,iVar1,iVar3);
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    if (-1 < iVar5 + -1) {
      iVar4 = 0;
      do {
        iVar6 = FUN_0040f6b0(piVar2,iVar4);
        if (iVar6 != 0) {
          FUN_004458dc(iVar6,(short)iVar4);
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    *in_FS_OFFSET = uStack_24;
    puStack_1c = (undefined1 *)0x441a4b;
    puStack_20 = (undefined1 *)0x441a43;
    FUN_00402eac(piVar2);
    return;
  }
  return;
}

