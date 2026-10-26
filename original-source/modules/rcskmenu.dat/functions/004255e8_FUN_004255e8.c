/*
 * FUN_004255e8 at 004255e8
 * undefined FUN_004255e8(void)
 * Address ranges: 004255e8-0042563d;00425645-00425648
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004255e8(int *param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  
  puStack_10 = (undefined1 *)0x4255fa;
  cVar2 = (**(code **)(*param_1 + 0x24))();
  if (cVar2 != '\0') {
    piVar1 = (int *)param_1[10];
    *(undefined1 *)(piVar1 + 0x7c) = 1;
    puStack_14 = &LAB_0042563e;
    uStack_18 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_18;
    puStack_10 = &stack0xfffffffc;
    (**(code **)(*piVar1 + 0xb8))(piVar1,param_2);
    *in_FS_OFFSET = uStack_18;
    *(undefined1 *)(param_1[10] + 0x1f0) = 0;
    return;
  }
  return;
}

