/*
 * FUN_00460608 at 00460608
 * undefined FUN_00460608(void)
 * Address ranges: 00460608-00460638
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00460608(int *param_1,int *param_2)

{
  bool bVar1;
  
  FUN_004427e8(param_1,param_2);
  bVar1 = FUN_0046063c((int)param_1);
  if ((!bVar1) && ((char)param_1[0x7e] != '\0')) {
    param_2[2] = param_2[2] | 0x20;
    param_2[1] = param_2[1] & 0xfdffffff;
  }
  return;
}

