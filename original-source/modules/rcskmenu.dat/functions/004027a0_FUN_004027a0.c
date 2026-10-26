/*
 * FUN_004027a0 at 004027a0
 * undefined __register FUN_004027a0(uint param_1)
 * Address ranges: 004027a0-004027c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004027a0(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  LPVOID pvVar3;
  undefined4 in_stack_00000000;
  
  uVar1 = param_1 & 0x7f;
  if (DAT_0047d004 != (code *)0x0) {
    uVar1 = (*DAT_0047d004)(uVar1,in_stack_00000000);
  }
  uVar2 = CONCAT31((int3)(uVar1 - 1 >> 8),*(undefined1 *)(uVar1 + 0x4027c8));
  if ((int)(uVar1 - 1) < 0) {
    pvVar3 = FUN_00406144();
    uVar2 = *(undefined4 *)((int)pvVar3 + 4);
  }
  FUN_00403b28(uVar2);
  return;
}

