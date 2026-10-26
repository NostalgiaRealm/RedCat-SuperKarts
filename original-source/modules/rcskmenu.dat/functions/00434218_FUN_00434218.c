/*
 * FUN_00434218 at 00434218
 * undefined __register FUN_00434218(int param_1, int * param_2)
 * Address ranges: 00434218-00434283
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00434218(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_18 = &LAB_00434284;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x20))();
    if (*(int *)(param_1 + 0x24) <= iVar1) {
      iVar1 = (**(code **)(*param_2 + 0x2c))();
      if (*(int *)(param_1 + 0x28) <= iVar1) goto LAB_0043426e;
    }
    FUN_00405438((undefined4 *)PTR_PTR_0047c6e0,(int *)&local_8);
    piVar2 = FUN_0040ac64((int *)&DAT_0040de0c,'\x01',local_8);
    FUN_00403604(piVar2);
  }
LAB_0043426e:
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0043428b;
  puStack_18 = (undefined1 *)0x434283;
  FUN_00403b50((int *)&local_8);
  return;
}

