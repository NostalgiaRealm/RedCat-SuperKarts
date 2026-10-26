/*
 * FUN_00446ad0 at 00446ad0
 * undefined FUN_00446ad0(void)
 * Address ranges: 00446ad0-00446b33
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00446ad0(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 4);
  if ((((((uVar1 < 0x100) || (0x108 < uVar1)) && (*(int *)(param_2 + 4) != 0xb000)) &&
       ((*(int *)(param_2 + 4) != 0xb001 && (*(int *)(param_2 + 4) != 0xb016)))) &&
      ((*(int *)(param_2 + 4) != 0xb017 && (*(int *)(param_2 + 4) != 0x111)))) &&
     (((*(uint *)(param_2 + 4) < 0x201 || (0x20a < *(uint *)(param_2 + 4))) &&
      (*(int *)(param_2 + 4) != 0xa0)))) {
    return 0;
  }
  return CONCAT31((int3)(uVar1 >> 8),1);
}

