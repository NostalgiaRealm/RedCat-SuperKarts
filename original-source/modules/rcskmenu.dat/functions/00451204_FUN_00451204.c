/*
 * FUN_00451204 at 00451204
 * undefined __register FUN_00451204(void)
 * Address ranges: 00451204-00451287
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451204(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000004;
  
  uVar1 = *(uint *)(in_stack_00000004 + -0x20);
  if ((int)uVar1 < 0) {
    iVar2 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
    if (-1 < iVar2 + -1) {
      iVar3 = 0;
      do {
        FUN_004118e8(*(int **)(in_stack_00000004 + -0x30),
                     *(int *)(*(int *)(in_stack_00000004 + -0x2c) + 0x478) +
                     *(int *)(*(int *)(in_stack_00000004 + -0x2c) + 0x430) * iVar3,
                     *(int *)(*(int *)(in_stack_00000004 + -0x2c) + 0x480));
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  else {
    FUN_004118e8(*(int **)(in_stack_00000004 + -0x30),
                 *(undefined4 *)(*(int *)(in_stack_00000004 + -0x2c) + 0x440),
                 *(int *)(*(int *)(in_stack_00000004 + -0x2c) + 0x474));
  }
  return;
}

