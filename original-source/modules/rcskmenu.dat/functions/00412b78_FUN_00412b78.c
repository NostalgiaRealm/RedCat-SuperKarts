/*
 * FUN_00412b78 at 00412b78
 * undefined __register FUN_00412b78(undefined4 param_1, undefined4 param_2, int param_3, int param_4)
 * Address ranges: 00412b78-00412c31;00412c49-00412c5d;00412c81-00412c85
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412b78(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  puStack_18 = &LAB_00412c5e;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_20 = (undefined1 *)0x412b9d;
  iVar2 = FUN_00414580(*(int *)(param_4 + -0xc),*(char **)(param_4 + -0x14),param_3);
  *(undefined4 *)(param_4 + -0x10) = 0;
  if (*(short *)(*(int *)(param_4 + -0xc) + 0x6a) != 0) {
    puStack_20 = (undefined1 *)(param_4 + -0x10);
    puStack_24 = (undefined1 *)0x412bcf;
    (**(code **)(*(int *)(param_4 + -0xc) + 0x68))
              (*(undefined4 *)(*(int *)(param_4 + -0xc) + 0x6c),*(undefined4 *)(param_4 + -0xc),
               iVar2);
  }
  if (*(int *)(param_4 + -0x10) == 0) {
    puStack_20 = (undefined1 *)0x412bdd;
    uVar3 = (**(code **)(iVar2 + -0xc))();
    *(undefined4 *)(param_4 + -0x10) = uVar3;
    if ((*(byte *)(param_4 + -1) & 4) != 0) {
      puVar1 = (ushort *)(*(int *)(param_4 + -0x10) + 0x20);
      *puVar1 = *puVar1 | 1;
      puVar1 = (ushort *)(*(int *)(param_4 + -0x10) + 0x20);
      *puVar1 = *puVar1 | 0x200;
    }
    puStack_24 = &LAB_00412c32;
    uStack_28 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_28;
    puStack_20 = &stack0xfffffffc;
    (**(code **)(**(int **)(param_4 + -0x10) + 0x2c))
              (*(int **)(param_4 + -0x10),0xffffffff,
               *(undefined4 *)(*(int *)(param_4 + -0xc) + 0x28));
    *in_FS_OFFSET = uStack_28;
  }
  puVar1 = (ushort *)(*(int *)(param_4 + -0x10) + 0x20);
  *puVar1 = *puVar1 | 1;
  *in_FS_OFFSET = uStack_1c;
  return;
}

