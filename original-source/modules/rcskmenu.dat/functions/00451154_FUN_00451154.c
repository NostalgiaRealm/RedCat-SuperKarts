/*
 * FUN_00451154 at 00451154
 * undefined __register FUN_00451154(void)
 * Address ranges: 00451154-004511aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00451154(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_stack_00000004;
  
  piVar3 = (int *)(in_stack_00000004 + -0x2c);
  iVar1 = *(int *)(in_stack_00000004 + -0x14);
  *(int *)(*piVar3 + 0x474) = iVar1;
  uVar2 = FUN_00402714(iVar1);
  *(undefined4 *)(*piVar3 + 0x440) = uVar2;
  *(undefined4 *)(*(int *)(*piVar3 + 0xc) + 0x14) = *(undefined4 *)(*piVar3 + 0x474);
  FUN_004118e8(*(int **)(in_stack_00000004 + -0x30),*(undefined4 *)(*piVar3 + 0x440),
               *(int *)(*piVar3 + 0x474));
  return;
}

