/*
 * FUN_00402260 at 00402260
 * undefined FUN_00402260(void)
 * Address ranges: 00402260-004022bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00402260(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *(uint *)(param_1 * 0xd0 + 4 + DAT_0067ee20) = *(uint *)(param_1 * 0xd0 + 4 + DAT_0067ee20) | 2;
  iVar1 = FUN_004028c0(param_1);
  if (iVar1 == -1) {
    FUN_00406f60();
    FUN_004140b0(param_1);
    return 0;
  }
  uVar2 = FUN_004028c0(param_1);
  FUN_004024d0(uVar2);
  uVar2 = FUN_004028c0(param_1);
  FUN_00406940(uVar2);
  return 0;
}

