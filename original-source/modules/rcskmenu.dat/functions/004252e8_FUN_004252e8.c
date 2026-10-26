/*
 * FUN_004252e8 at 004252e8
 * undefined __register FUN_004252e8(int param_1, undefined4 param_2, LONG * param_3, undefined2 param_4)
 * Address ranges: 004252e8-0042538f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004252e8(int param_1,undefined4 param_2,LONG *param_3,undefined2 param_4)

{
  int iVar1;
  RECT *pRVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffc8;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined *local_18;
  RECT local_14;
  
  puStack_28 = &stack0xfffffffc;
  local_18 = (undefined *)0x0;
  pRVar2 = &local_14;
  for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
    pRVar2->left = *param_3;
    param_3 = param_3 + 1;
    pRVar2 = (RECT *)&pRVar2->top;
  }
  puStack_2c = &LAB_00425390;
  puStack_30 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_30;
  FUN_0043e3f8(*(int *)(param_1 + 500));
  if (*(short *)(param_1 + 0x242) == 0) {
    FUN_00418538(*(int **)(param_1 + 500),&local_14);
    (**(code **)(**(int **)(param_1 + 0x1f0) + 0xc))(*(int **)(param_1 + 0x1f0),param_2,&local_18);
    FUN_00418724(*(int **)(param_1 + 500),local_14.left + 2,local_14.top,local_18);
  }
  else {
    in_stack_ffffffc8 = CONCAT22((short)((uint)&local_14 >> 0x10),param_4);
    (**(code **)(param_1 + 0x240))
              (*(undefined4 *)(param_1 + 0x244),param_1,param_2,in_stack_ffffffc8,&local_14);
  }
  *in_FS_OFFSET = in_stack_ffffffc8;
  puStack_30 = &LAB_00425397;
  FUN_00403b50((int *)&local_18);
  return;
}

