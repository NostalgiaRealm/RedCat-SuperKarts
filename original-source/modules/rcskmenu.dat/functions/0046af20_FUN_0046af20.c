/*
 * FUN_0046af20 at 0046af20
 * undefined FUN_0046af20(void)
 * Address ranges: 0046af20-0046af6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0046af20(int param_1)

{
  undefined1 uVar1;
  
  FUN_0046b154(param_1);
  uVar1 = FUN_0045bb60(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  *(undefined1 *)(param_1 + 0x365) = uVar1;
  uVar1 = FUN_0045bb58(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  *(undefined1 *)(param_1 + 0x366) = uVar1;
  FUN_0046af90(param_1);
  FUN_0045bbac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c),0);
  return 1;
}

