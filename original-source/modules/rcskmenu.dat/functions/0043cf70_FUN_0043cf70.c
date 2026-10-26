/*
 * FUN_0043cf70 at 0043cf70
 * undefined FUN_0043cf70(void)
 * Address ranges: 0043cf70-0043cf87
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined2 FUN_0043cf70(int param_1,char param_2)

{
  undefined2 uVar1;
  
  if (param_2 == '\0') {
    uVar1 = 0xfff3;
  }
  else {
    uVar1 = *(undefined2 *)(*(int *)(param_1 + 0x38) + 0x6a);
  }
  return uVar1;
}

