/*
 * FUN_00423930 at 00423930
 * undefined FUN_00423930(void)
 * Address ranges: 00423930-0042394b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00423930(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(param_1 + 0x58) = 0;
    uVar1 = (**(code **)(**(int **)(param_1 + 0x54) + 0xc))(*(int **)(param_1 + 0x54),param_1);
    return uVar1;
  }
  return 0;
}

