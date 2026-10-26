/*
 * FUN_00473c44 at 00473c44
 * undefined FUN_00473c44(void)
 * Address ranges: 00473c44-00473cba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00473c44(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  
  FUN_00473a98(param_1);
  FUN_00473bb4(param_1);
  *(undefined1 *)(param_1 + 0x338) =
       *(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22);
  uVar1 = FUN_0045a9e0(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80));
  *(undefined1 *)(param_1 + 0x339) = uVar1;
  cVar2 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  (**(code **)(**(int **)(param_1 + 0x2e4) + 0x5c))(*(int **)(param_1 + 0x2e4),cVar2 == '\x02');
  FUN_00473ddc();
  FUN_00473d50(param_1);
  FUN_004740f8(param_1);
  return 1;
}

