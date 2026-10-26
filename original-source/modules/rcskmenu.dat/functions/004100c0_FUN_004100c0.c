/*
 * FUN_004100c0 at 004100c0
 * undefined __register FUN_004100c0(int * param_1, int * param_2)
 * Address ranges: 004100c0-0041013d;00410145-00410154
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004100c0(int *param_1,int *param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  puStack_18 = (undefined1 *)0x4100d9;
  uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_0040e0cc);
  if ((char)uVar2 != '\0') {
    puStack_18 = (undefined1 *)0x4100e5;
    (**(code **)(*param_1 + 0x14))();
    puStack_1c = &LAB_0041013e;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    puStack_18 = &stack0xfffffffc;
    FUN_0041016c(param_1);
    iVar3 = FUN_00410210((int)param_2);
    if (-1 < iVar3 + -1) {
      iVar5 = 0;
      do {
        uVar2 = FUN_00410218((int)param_2,iVar5);
        piVar4 = (int *)FUN_004100b4((int)param_1);
        (**(code **)(*piVar4 + 8))(piVar4,uVar2);
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    puVar1 = puStack_18;
    *in_FS_OFFSET = uStack_20;
    puStack_18 = (undefined1 *)0x41014f;
    puStack_1c = (undefined1 *)0x41013d;
    (**(code **)(*param_1 + 0x18))(param_1,*param_1,puVar1);
    return;
  }
  puStack_18 = (undefined1 *)0x41014f;
  FUN_0040fca8(param_1,param_2);
  return;
}

